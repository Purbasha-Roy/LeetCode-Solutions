class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int ans=INT_MAX;
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            vector<int> dis(n,-1);
            vector<int> parent(n,-1);
            queue<int> q;
            q.push(i);
            dis[i]=0;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(dis[it]==-1){
                        dis[it]=dis[node]+1;
                        q.push(it);
                        parent[it]=node;
                    }
                    else if(parent[node]!=it){
                        ans=min(ans,dis[node]+dis[it]+1);
                    }
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};