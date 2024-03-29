class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mp;
        int i=0;
        int j=0;
        int count=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            while(mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }
            count=max(count,j-i+1);
            j++;
        }
        return count;
    }
};