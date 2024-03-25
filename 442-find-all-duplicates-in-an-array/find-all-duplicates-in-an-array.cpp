class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
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