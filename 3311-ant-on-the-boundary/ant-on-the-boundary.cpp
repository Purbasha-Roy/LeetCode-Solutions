class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            res+=nums[i];
            if(abs(res)==0){
                ans++;
            }
        }
        return ans;
    }
};