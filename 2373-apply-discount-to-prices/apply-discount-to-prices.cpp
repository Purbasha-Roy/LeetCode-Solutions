class Solution {
public:
    string discountPrices(string sentence, int discount) {
        vector<string> arr;
        stringstream ss(sentence);
        string word;
        while(ss>>word){
            arr.push_back(word);
        }
        for(int i=0;i<arr.size();i++){
            string x=arr[i];
            bool found=false;
            string num="";
            for(int j=0;j<x.size();j++){
                if(j==0 && x[j]=='$') found=true;
                else if(found){
                    if(x[j]>='0' && x[j]<='9') num+=x[j];
                    else{
                        found=false;
                        break;
                    }
                }
                else{
                    break;
                }
            }
            if(found && num.size()>0){
                long long number=stoll(num);
                long double discountprice=(number*discount)/100.0;
                long double finalnum=number-discountprice;
                arr[i]="$";
                arr[i]+=to_string(finalnum);
                int minus=4;
                while(minus--){
                    arr[i].pop_back();
                }
            }
        }
        string ans="";
        for(auto it: arr){
            ans+=it+" ";
        }
        ans.pop_back();
        return ans;
    }
};