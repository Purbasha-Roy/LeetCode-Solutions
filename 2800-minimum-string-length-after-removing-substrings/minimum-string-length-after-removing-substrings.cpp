class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='B'){
                if(st.size()>=1 && st.top()=='A'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            else if(s[i]=='D'){
                if(st.size()>=1 && st.top()=='C'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }

            }
            else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};