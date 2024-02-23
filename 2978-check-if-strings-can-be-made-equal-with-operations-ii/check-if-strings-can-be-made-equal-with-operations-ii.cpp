class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string evens1="";
        string odds1="";
        string evens2="";
        string odds2="";
        for(int i=0;i<s1.size();i++){
            if(i%2==0){
                evens1.push_back(s1[i]);
            }
            else{
                odds1.push_back(s1[i]);
            }
        }
        for(int i=0;i<s2.size();i++){
            if(i%2==0){
                evens2.push_back(s2[i]);
            }
            else{
                odds2.push_back(s2[i]);
            }
        }
        sort(evens1.begin(),evens1.end());
        sort(odds1.begin(),odds1.end());
        sort(evens2.begin(),evens2.end());
        sort(odds2.begin(),odds2.end());
        
        return evens1==evens2 && odds1==odds2;
    }
};