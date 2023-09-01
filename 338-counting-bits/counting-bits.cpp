class Solution {
public:
    int countone(int n){
        int ans=0;
        while(n>0){
            if(n%2==1){
                ans++;
            }
            n=n/2;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int tot=countone(i);
            ans.push_back(tot);
        }
        return ans;
    }
};