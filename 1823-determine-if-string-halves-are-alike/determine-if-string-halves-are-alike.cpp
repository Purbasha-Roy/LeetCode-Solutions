class Solution {
public:
    int countvowel(string s, int start, int end){
        int ans=0;
        for(int i=start;i<=end;i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='u' || s[i]=='i'){
                ans++;
            }
        }
        return ans;
    }
    bool halvesAreAlike(string s) {
        int start=0;
        int end=s.size()-1;
        int mid=(start+end)/2;
        int a=countvowel(s,start,mid);
        int b=countvowel(s,mid+1,end);
        if(a==b){
            return true;
        }
        return false;
    }
};