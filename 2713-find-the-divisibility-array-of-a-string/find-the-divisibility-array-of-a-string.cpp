class Solution {
public:
    long long num=0;
    bool divisible(char s, int m){
        int x=s-'0';
        num=(num*10)%m+x;
        if(num%m==0){
            return true;
        }
        return false;
    }
    vector<int> divisibilityArray(string word, int m) {
        int n=word.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(divisible(word[i],m)){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};