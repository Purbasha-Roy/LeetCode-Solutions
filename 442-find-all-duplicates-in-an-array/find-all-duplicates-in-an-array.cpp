class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // METHOD 1
        // vector<int> ans;
        // map<int,int> mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it:mp){
        //     if(it.second==2){
        //         ans.push_back(it.first);
        //     }
        // }
        // return ans;

        int n=nums.size();
        vector<int> count(n+1,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(count[nums[i]]>0){
                ans.push_back(nums[i]);
            }
            else{
                count[nums[i]]+=1;
            }
        }
        return ans;
    }
};