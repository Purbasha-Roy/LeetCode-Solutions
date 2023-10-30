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
vector<int> ans;
void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
}
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        inorder(root);
        root->val=ans[0];
        TreeNode* temp=root;
        root->left==NULL;
        int i=1;
        while(i<ans.size()){
            temp->right=new TreeNode(ans[i]);
            temp->left=NULL;
            temp=temp->right;
            i++;
        }
        return root;
    }
};