class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int count=0;
        int len=min({s1.size(),s2.size(),s3.size()});
        int i=0;
        while(i<len){
            if(s1[i]==s2[i] && s2[i]==s3[i]){
                count++;
            }
            else break;
            i++;
        }
        if(count==0) return -1;
        return s1.size()+s2.size()+s3.size()-3*count;
    }
};