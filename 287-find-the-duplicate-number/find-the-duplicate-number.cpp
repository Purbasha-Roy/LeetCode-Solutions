class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    //METHOD 1
    // unordered_map<int,int> count;
    // for(int i=0;i<nums.size();i++){
    //     count[nums[i]]++;
    // }
    // for(auto it:count){
    //     if(it.second>1){
    //         return it.first;
    //     }
    // }
    // return -1;  

    //METHOD 2
    // sort(nums.begin(),nums.end());
    // for(int i=0;i<nums.size()-1;i++){
    //     if(nums[i]==nums[i+1]){
    //         return nums[i];
    //     }
    // }
    // return -1;

    //METHOD 3
    int n=nums.size();
    int freq[n+1];
    memset(freq,0,sizeof(freq));
    for(int i=0;i<n;i++){
        if(freq[nums[i]]==0){
            freq[nums[i]]++;
        }
        else{
            return nums[i];
        }
    }
    return -1;
    }
};