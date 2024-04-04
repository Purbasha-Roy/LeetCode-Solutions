class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int l=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                l++;
            }
            else if(s[i]==')'){
                ans=max(ans,l);
                l--;
            }
        }
        return ans;
    }
};