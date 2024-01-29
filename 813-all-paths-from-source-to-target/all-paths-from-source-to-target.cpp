class Solution {
public:
    void function(vector<vector<int>> &ans, vector<int> path, vector<vector<int>> graph, int start, int destination){
        path.push_back(start);
        if(start==destination){
            ans.push_back(path);
            return;
        }
        for(auto it:graph[start]){
            function(ans,path,graph,it,destination);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        int nodes=graph.size();
        if(nodes==0) return ans;
        function(ans,path,graph,0,nodes-1);
        return ans;
    }
};