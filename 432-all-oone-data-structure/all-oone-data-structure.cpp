class AllOne {
public:
priority_queue<pair<int,string>> maxi;
priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> mini;
map<string,int> mp;
    AllOne() {
        
    }
    
    void inc(string key) {
        mp[key]++;
        maxi.push({mp[key],key});
        mini.push({mp[key],key});
    }
    
    void dec(string key) {
        mp[key]--;
        maxi.push({mp[key],key});
        mini.push({mp[key],key});
    }
    
    string getMaxKey() {
        while(maxi.size()){
            if(mp[maxi.top().second] && maxi.top().first==mp[maxi.top().second]){
                return maxi.top().second;
            }
            else{
                maxi.pop();
            }
        }
        return "";
    }
    
    string getMinKey() {
        while(mini.size()){
            if(mp[mini.top().second] && mini.top().first==mp[mini.top().second]){
                return mini.top().second;
            }
            else{
                mini.pop();
            }
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */