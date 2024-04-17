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
    void dfs(TreeNode* node, string path, string& ans){
        if(node==NULL) return;
        path+=char('a'+node->val);
        if(node->left==NULL && node->right==NULL){
            reverse(path.begin(),path.end());
            if(path<ans || ans.empty()){
                ans=path;
            }
            //reverse(path.begin(),path.end());
        }
        dfs(node->left,path,ans);
        dfs(node->right,path,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        dfs(root,"",ans);
        return ans;
    }
};