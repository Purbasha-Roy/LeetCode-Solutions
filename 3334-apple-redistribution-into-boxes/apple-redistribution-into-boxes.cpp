class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int count=0;
        int sum=0;
        int total=accumulate(apple.begin(),apple.end(),sum);
        int ans=0;
        for(int i=capacity.size()-1;i>=0;i--){
            if(ans>=total){
                break;
            }
            ans+=capacity[i];
            count++;
        }
        return count;
    }
};