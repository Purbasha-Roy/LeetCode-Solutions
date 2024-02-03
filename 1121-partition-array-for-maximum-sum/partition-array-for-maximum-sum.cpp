class Solution {
public:
    int func(int index, vector<int>& arr, int k, int n, vector<int>&dp){
        if(index==n) return 0;
        if(dp[index]!=-1) return dp[index];
        int maxi=INT_MIN;
        int maxsum=INT_MIN;
        int len=0;
        for(int j=index;j<min(index+k,n);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=maxi*len+func(j+1,arr,k,n,dp);
            maxsum=max(maxsum,sum);
        }
        return dp[index]=maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return func(0, arr, k, n,dp
        );
    }
};