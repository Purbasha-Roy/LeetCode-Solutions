class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_set<int> s(restricted.begin(), restricted.end());
        queue<int> q;
        int res=0;
        q.push(0);
        s.insert(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res++;
            for(auto it:adj[node]){
                if(s.find(it)==s.end()){
                    q.push(it);
                    s.insert(it);
                }
            }
        }
        return res;
    }
};