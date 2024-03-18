class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(),h.end());
        long sum=0;
        int min=0;
        for(int i=h.size()-1;i>=0 && k>0;i--){
            k--;
            if(min<h[i]) sum+=h[i]-min;
            min++;
        }
        return sum;
    }
};