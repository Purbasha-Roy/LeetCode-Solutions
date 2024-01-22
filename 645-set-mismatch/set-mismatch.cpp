class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int a=0;
        int b=0;
        int n=nums.size()+1;
        vector<int> mp(n,0);
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=1;i<=nums.size();i++){
            if(mp[i]==0){
                a=i;
            }
            if(mp[i]==2){
                b=i;
            }
        }
        return {b,a};
    }
};