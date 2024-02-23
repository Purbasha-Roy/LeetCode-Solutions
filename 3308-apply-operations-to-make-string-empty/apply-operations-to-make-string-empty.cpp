class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char,int> mp;
        int maxi=INT_MIN;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            maxi=max(maxi,mp[s[i]]);
        }
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            if(mp[s[i]]==maxi){
                ans.push_back(s[i]);
                mp[s[i]]--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};