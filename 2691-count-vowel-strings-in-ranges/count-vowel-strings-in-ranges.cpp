class Solution {
public:
    bool isvowel(char s){
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u'){
            return true;
        }
        return false;
    }
    bool vowelcheck(string s){
        return isvowel(s.front()) && isvowel(s.back());
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int count=0;
        for(int i=0;i<words.size();i++){
            if(vowelcheck(words[i])){
                count++;
            }
            ans.push_back(count);
        }
        vector<int> result;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int diff=ans[r]  - (l>0 ? ans[l-1] : 0);
            result.push_back(diff);
        }
        return result;
    }
};