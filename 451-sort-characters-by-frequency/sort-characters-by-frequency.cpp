class Solution {
public:
    string frequencySort(string s) {
        map<char,int> count;
        for(int i=0;i<s.size();i++){
            count[s[i]]++;
        }
        multimap<int,char,greater<int>> count1;
        for(auto it:count){
            count1.insert({it.second,it.first});
        }
        string ans="";
        for(auto it:count1){
            for(int i=0;i<it.first;i++){
                ans+=it.second;
            }
        }
        return ans;
    }
};