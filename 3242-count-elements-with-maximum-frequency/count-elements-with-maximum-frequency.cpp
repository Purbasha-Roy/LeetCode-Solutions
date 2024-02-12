class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int freq=INT_MIN;
        for(auto it:mp){
            if(it.second>freq){
                freq=it.second;
            }
        }
        int ans=0;
        for(auto it:mp){
            if(it.second==freq){
                ans+=it.second;
            }
        }
        return ans;
    }
};