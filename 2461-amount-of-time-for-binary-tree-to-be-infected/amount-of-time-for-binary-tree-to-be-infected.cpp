/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int ans=0;
void createadj(TreeNode* root, vector<vector<int>>& adj){
    if(root==NULL){
        return;
    }
    if(root->left){
        adj[root->val].push_back(root->left->val);
        adj[root->left->val].push_back(root->val);
    }
    if(root->right){
        adj[root->val].push_back(root->right->val);
        adj[root->right->val].push_back(root->val);
    }
    createadj(root->left,adj);
    createadj(root->right,adj);
}
void time(int start, vector<vector<int>> &adj, vector<int> &vis){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int node=q.front();
            vis[node]=1;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                }
            }
        }
        ans++;
    }
}
    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL){
            return 0;
        }
        vector<vector<int>> adj(100001);
        vector<int> vis(100001,0);
        createadj(root,adj);
        time(start,adj,vis);
        return ans-1;
    }
};