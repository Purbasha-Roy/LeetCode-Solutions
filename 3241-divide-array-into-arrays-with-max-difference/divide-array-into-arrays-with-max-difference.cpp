class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        n=n/3;
        vector<vector<int>> ans(n, vector<int>(3));
        int index=0;
        for(int i=0;i<nums.size();i=i+3){
            if(i+2<nums.size() && nums[i+2]-nums[i]<=k){
                ans[index]={nums[i],nums[i+1],nums[i+2]};
                index++;
            }
            else{
                return vector<vector<int>>();
            }
        }
        return ans;
    }
};