class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count1=0;
        int count0=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') count1++;
            else count0++;
        }
        string ans="";
        for(int i=0;i<count1-1;i++){
            ans+='1';
        }
        for(int i=0;i<count0;i++){
            ans+='0';
        }
        ans+='1';
        return ans;
    }
};