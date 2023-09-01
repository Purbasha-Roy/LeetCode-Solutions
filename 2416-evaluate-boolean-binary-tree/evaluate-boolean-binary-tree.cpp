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
int value=0;
    int helperfunction(TreeNode* root){
        if(root==NULL){
            return value;
        }
        if(root->val==1){
            value=1;
        }
        if(root->val==0){
            value=0;
        }
        int left=helperfunction(root->left);
        int right=helperfunction(root->right);
        if(root->val==2){
            value=left|right;
        }
        if(root->val==3){
            value=left&right;
        }
        return value;
    }
    bool evaluateTree(TreeNode* root) {
        helperfunction(root);
        return value==1;
    }
};