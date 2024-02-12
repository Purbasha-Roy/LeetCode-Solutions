class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> mp;
        for(int i=0;i<access_times.size();i++){
            int time=stoi(access_times[i][1]);
            mp[access_times[i][0]].push_back(time);
        }
        vector<string> ans;
        for(auto [name,times]:mp){
            sort(times.begin(),times.end());
            for(int i=1;i<times.size()-1;i++){
                int diff=times[i+1]-times[i-1];
                if(diff<100){
                    ans.push_back(name);
                    break;
                }
            }
        }
        return ans;
    }
};