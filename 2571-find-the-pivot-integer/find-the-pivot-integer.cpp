class Solution {
public:
    int pivotInteger(int n) {
        int start=1;
        int end=n;
        int i=0;
        while(start<=end && i<log(n)+1){
            int mid=(end+start)/2.0;
            int firstsum=mid*(mid+1)/2;
            int secondsum=(n-mid+1)*(n+mid)/2;
            if(firstsum==secondsum){
                return mid;
            }
            else if(firstsum>secondsum){
                end=mid;
            }
            else{
                start=mid;
            }
            i++;
        }
        return -1;
    }
};