class Solution {
public:
    string finalString(string s) {
        string t="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='i'){
                reverse(t.begin(),t.end());
            }
            else{
                t+=s[i];
            }
        }
        return t;
    }
};