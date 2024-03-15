class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        int n=nums.size();
        vector<int> left;
        int right[n];
        vector<int> ans;
        for(int i=0;i<n;i++){
            product=product*nums[i];
            left.push_back(product);
        }
        product=1;
        for(int j=n-1;j>=0;j--){
            product=product*nums[j];
            right[j]=product;
        }
        for(int i=0;i<n;i++){
            if(i==0){
                ans.push_back(right[1]);
            }
            else if(i==n-1){
                ans.push_back(left[n-2]);
            }
            else{
                ans.push_back(left[i-1]*right[i+1]);
            }
        }
        return ans;   
    }
};