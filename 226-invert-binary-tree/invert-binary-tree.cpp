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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        v.push_back(root->val);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                v.push_back(node->left->val);
            }
            else{
                v.push_back(1000);
            }
            if(node->right){
                q.push(node->right);
                v.push_back(node->right->val);
            }
            else{
                v.push_back(1000);
            }
        }
        TreeNode* root1=new TreeNode(root->val);
        int i=1;
        q.push(root1);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(v[i]==1000){
                node->right=NULL;
                i++;
            }
            else{
                node->right=new TreeNode(v[i]);
                q.push(node->right);
                i++;
            }
            if(v[i]==1000){
                node->left=NULL;
                i++;
            }
            else{
                node->left=new TreeNode(v[i]);
                q.push(node->left);
                i++;
            }
        }
        return root1;
    }
};