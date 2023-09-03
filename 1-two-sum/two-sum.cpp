class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //METHOD 1
        // int a=0;
        // int b=0;
        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             a=i;
        //             b=j;
        //         }
        //     }
        // }
        // return {a,b};

        //METHOD 2
          unordered_map<int,int> ans;
          for(int i=0;i<nums.size();i++){
              int diff=target-nums[i];
              if(ans.find(diff)!=ans.end()){
                  return {ans[diff],i};
              }
              ans[nums[i]]=i;
          }
          return {-1,-1};
    }
};