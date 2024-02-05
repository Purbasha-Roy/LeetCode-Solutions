class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(27,0);
        for(int i=0;s[i]!='\0';i++){
            count[s[i]-'a']++;
        }
        for(int i=0;s[i]!='\0';i++){
            if(count[s[i]-'a']==1){
                return i;
            }
        }
        return -1;   
    }
};