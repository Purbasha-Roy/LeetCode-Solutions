class Solution {
public:
    int atmost(vector<int> nums, int k){
        int i=0;
        int j=0;
        int n=nums.size();
        int count=0;
        map<int,int> mp;
        while(i<n){
            mp[nums[i]]++;
            while(mp.size()>k){
                auto it=mp.find(nums[j]);
                it->second--;
                if(it->second==0){
                    mp.erase(it);
                }
                j++;
            }
            count=count+(i-j+1);
            i++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return  atmost(nums,k)-atmost(nums,k-1);
    }
};