class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto it:mp){
            int x=it.second;
            if(x==1) return -1;
            ans+=x/3;
            if(x%3) ans++;
        }
        return ans;
    }
};