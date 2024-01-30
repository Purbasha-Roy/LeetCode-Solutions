class Solution {
public:
    bool isoperator(string& op){
        return op=="+" || op=="*" || op=="-" || op=="/";
    }
    int func(int a, int b, char op){
        if(op=='+') return a+b;
        if(op=='-') return a-b;
        if(op=='*') return a*b;
        if(op=='/') return a/b;
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it:tokens){
            if(isoperator(it)){
                // if(st.size()<2){
                //     return -11;
                // }
                int integer2=st.top();
                st.pop();
                int integer1=st.top();
                st.pop();
                int ans=func(integer1,integer2,it[0]);
                // cout<<ans<<endl;
                st.push(ans);
            }
            else{
                cout<<stoi(it)<<endl;
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};