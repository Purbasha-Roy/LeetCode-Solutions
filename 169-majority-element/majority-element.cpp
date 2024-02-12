class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> output;
        for(int i=0;i<n;i++){
            output[nums[i]]++;
        }
        int x=n/2;
        for(auto it:output){
            if(it.second>x){
                return it.first;
            }
        }
        return -1;
    }
};