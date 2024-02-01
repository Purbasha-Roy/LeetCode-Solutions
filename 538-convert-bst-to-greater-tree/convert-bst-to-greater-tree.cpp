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
stack<TreeNode*> st;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        st.push(root);
        inorder(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        int sum=0;
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            sum+=node->val;
            node->val=sum;
        }
        return root;
    }
};