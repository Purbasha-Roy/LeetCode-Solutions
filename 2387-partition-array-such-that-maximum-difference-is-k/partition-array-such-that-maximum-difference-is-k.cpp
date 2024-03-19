class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int maxi=0;
        for(int i=0;i<nums.size();){
            ans++;
            maxi=nums[i]+k;
            while(i<nums.size() && nums[i]<=maxi) i++;
        }
        return ans;
    }
};