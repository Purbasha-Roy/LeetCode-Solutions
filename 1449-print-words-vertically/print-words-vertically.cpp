class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        string word;
        stringstream ss(s);
        while(ss>>word){
            words.push_back(word);
        }
        int len=0;
        for(int i=0;i<words.size();i++){
            len=max(len, static_cast<int>(words[i].size()));
        }
        vector<string> ans(len, string(words.size(),' '));
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                ans[j][i]=words[i][j];
            }
        }
        for(auto& it:ans){
            while(it.back()==' '){
                it.pop_back();
            }
        }
        return ans;
    }
};