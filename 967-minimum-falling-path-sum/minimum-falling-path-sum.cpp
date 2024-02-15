class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp=matrix;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int minele=dp[i-1][j];
                if(j>0) minele=min(minele,dp[i-1][j-1]);
                if(j<n-1) minele=min(minele,dp[i-1][j+1]);
                dp[i][j]+=minele;
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};