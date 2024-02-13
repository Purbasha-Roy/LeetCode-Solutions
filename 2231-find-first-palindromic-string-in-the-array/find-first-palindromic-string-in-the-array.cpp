class Solution {
public:
    bool ispalindrome(string word){
        int start=0;
        int end=word.size()-1;
        while(start<=end){
            if(word[start]!=word[end]){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(ispalindrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
};