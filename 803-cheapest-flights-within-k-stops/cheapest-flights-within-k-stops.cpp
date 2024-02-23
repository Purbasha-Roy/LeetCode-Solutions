class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dis(n,1e9);
        dis[src]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int count=q.front().first;
            int node=q.front().second.first;
            int price=q.front().second.second;
            q.pop();
            if(count>k) continue;
            for(auto it:adj[node]){
                int newp=it.second;
                int newn=it.first;
                if(newp+price<dis[newn] && count<=k){
                    dis[newn]=newp+price;
                    q.push({count+1,{newn, newp+price}});
                }
            }
        }
        if(dis[dst]==1e9){
            return -1;
        }
        return dis[dst];
    }
};