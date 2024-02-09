class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        int maxindex=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>dp[maxindex]){
                maxindex=i;
            }
        }
        vector<int> ans;
        for(int i=maxindex;i!=-1;i=prev[i]){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};