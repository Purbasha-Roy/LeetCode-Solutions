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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> rootcheck;
        for(auto it:descriptions){
            int parent=it[0];
            int child=it[1];
            bool isleft=it[2];
            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }
            if(mp.find(parent)==mp.end()){
                mp[parent]=new TreeNode(parent);
            }
            if(isleft){
                mp[parent]->left=mp[child];
            }
            else{
                mp[parent]->right=mp[child];
            }
            rootcheck.insert(child);
        }   
        TreeNode* root;
        for(auto it:mp){
            if(rootcheck.find(it.first)==rootcheck.end()){
                root=it.second;
                break;
            }
        }
        return root;
    }
};