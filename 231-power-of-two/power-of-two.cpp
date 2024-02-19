class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0){
            return false;
        }
        if(n==0){
            return false;
        }
        if(n==1){
            return true;
        }
        bool ans=true;
        while(abs(n)>1){
            if(n%2!=0){
                ans=false;
                break;
            }
            n=n/2;
        }
        return ans;
    }
};