class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        int ans=0;
        int left=0;
        int right=0;
        while(right<n){
            mp[s[right]]++;
            if(mp[s[right]]<=2){
                ans=max(ans,right-left+1);
                right++;
            }
            else{
                while(mp[s[right]]>2){
                    mp[s[left]]--;
                    if(mp[s[left]]==0){
                        mp.erase(s[left]);
                    }
                    left++;
                }
                right++;
            }
        }
        return ans;
    }
};