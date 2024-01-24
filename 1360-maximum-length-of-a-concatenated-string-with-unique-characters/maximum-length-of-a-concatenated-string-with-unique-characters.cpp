class Solution {
public:
    bool isUnique(string a, string b){
        vector<bool> vec(26,false);
        for(auto c:a){
            if(vec[c-'a']==true) return false;
            else vec[c-'a']=true;
        }
        for(auto c:b){
            if(vec[c-'a']==true) return false;
            else vec[c-'a']=true;
        }
        return true;
    }
    void function(int& ans, int index, string& current, vector<string>& arr){
       if(index==arr.size()){
           ans=max(ans,static_cast<int>(current.size()));
           return;
       } 

       //Include the string
       if(isUnique(current,arr[index])){
           current+=arr[index];
           function(ans,index+1,current,arr);
           current.erase(current.length()-arr[index].length());
       }

       //Exclude the string
       function(ans,index+1,current,arr);
    }
    int maxLength(vector<string>& arr) {
        int ans=0;
        string current="";
        function(ans,0,current,arr);
        return ans;
    }
};