class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        for(int i=nums.size()-1;i>=0;i--){
            sum-=nums[i];
            if(sum>nums[i]){
                return sum+nums[i];
            }
            else{
                continue;
            }
        }
        return -1;
    }
};