class Solution {
public:
    int ispalindrome(string s, int left, int right){
        int count=0;
        while(left>=0 && right<s.length() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int odd=ispalindrome(s,i,i);
            int even=ispalindrome(s,i,i+1);
            ans=ans+odd+even;
        }
        return ans;
    }
};