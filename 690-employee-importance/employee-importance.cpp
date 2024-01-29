/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void func(int& ans, unordered_map<int,int> empimp, unordered_map<int,vector<int>> adj, int id){
        queue<int> q;
        q.push(id);
        while(!q.empty()){
            int empid=q.front();
            q.pop();
            ans+=empimp[empid];
            for(auto it:adj[empid]){
                q.push(it);
            }
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,int> empimp;
        int n=employees.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            int id=employees[i]->id;
            int importance=employees[i]->importance;
            empimp[id]=importance;
            vector<int> sub=employees[i]->subordinates;
            for(int j=0;j<sub.size();j++){
                adj[id].push_back(sub[j]);
            }
        }   
        int ans=0;
        func(ans,empimp,adj,id);
        return ans;  
    }
};