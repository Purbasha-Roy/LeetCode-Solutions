class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.length()<t.length()){
            return "";
        }
        vector<int> mp(256,0);
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        int start=0;
        int end=0;
        int ans_start=0;
        int minlength=INT_MAX;
        int count=0;
        while(end<s.length()){
            if(mp[s[end]]>0){
                count++;
            }
            mp[s[end]]--;
            while(count==t.length()){
                if(minlength>end-start+1){
                    minlength=end-start+1;
                    ans_start=start;
                }
                mp[s[start]]++;
                if(mp[s[start]]>0){
                    count--;
                }
                start++;
            }
            end++;
        }
        if(minlength==INT_MAX){
            return "";
        }
        return s.substr(ans_start,minlength);
    }
};