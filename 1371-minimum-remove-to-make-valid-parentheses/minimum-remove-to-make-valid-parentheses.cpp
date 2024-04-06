class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0;
        int close=0;
        int flag=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
                flag++;
            }
            else if(s[i]==')' && flag>0){
                flag--;
                close++;
            }
        }
        int k=min(open,close);
        open=k;
        close=k;
        string ans="";
        for(auto c:s){
            if(c=='('){
                if(open>0){
                    open--;
                    ans+='(';
                }
            }
            else if(c==')'){
                if(close>0 && close>open){
                    ans+=')';
                    close--;
                }
            }
            else{
                ans+=c;
            }
        }
        return ans;
    }
};