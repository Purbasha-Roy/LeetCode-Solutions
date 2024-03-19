class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        map<char,int> mp;
        int ans=0;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        for(auto it:mp){
            pq.push(it.second);
        }
        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }
            for(auto it:temp){
                if(it>0){
                    pq.push(it);
                }
            }
            if(pq.empty()){
                ans+=temp.size();
            }
            else{
                ans+=n+1;
            }
        }
        return ans;
    }
};