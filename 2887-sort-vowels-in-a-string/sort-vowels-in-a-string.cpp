class Solution {
public:
    bool isvowel(char s){
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u' || s=='A' || s=='E' || s=='I' || s=='O' || s=='U'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        vector<char> vowel;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                vowel.push_back(s[i]);
            }
        }
        sort(vowel.begin(),vowel.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                s[i]=vowel[j];
                j++;
            }
        }
        return s;
    }
};