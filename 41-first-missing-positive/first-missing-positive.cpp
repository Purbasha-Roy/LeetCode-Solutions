class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        int i=1;
        while(i<=nums.size()){
            if(count.find(i)==count.end()){
                return i;
            }
            else{
                i++;
            }
        }
        return nums.size()+1;
    }
};