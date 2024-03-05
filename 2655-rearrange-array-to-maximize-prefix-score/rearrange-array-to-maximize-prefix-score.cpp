class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long ans=0;
        if(nums[0]<=0) return 0;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
            if(ans<=0){
                return i;
            }
        }
        return nums.size();
    }
};