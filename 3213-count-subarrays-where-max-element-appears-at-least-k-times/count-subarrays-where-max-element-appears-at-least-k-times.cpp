class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int maxele=*max_element(nums.begin(),nums.end());
        long long int count=0, left=0, right=0, ans=0;
        int n=nums.size();
        while(right<n){
            if(nums[right]==maxele) count++;
            while(count>=k){
                if(nums[left]==maxele) count--;
                left++;
                ans+=n-right;
            }
            right++;
        }
        return ans;
    }
};