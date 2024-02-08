class Solution {
public:
    int solvedp(int n, vector<int>& dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int temp=i*i;
            ans=min(ans,1+solvedp(n-temp,dp));
        }
        dp[n]=ans;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solvedp(n,dp);
    }
};