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
// vector<int> ans;
// void inorder(TreeNode* root){
//     if(root==NULL){
//         return;
//     }
//     inorder(root->left);
//     ans.push_back(root->val);
//     inorder(root->right);
// }
    vector<int> inorderTraversal(TreeNode* root) {
        // inorder(root);
        // return ans;

        //METHOD 2
        stack<TreeNode*> s;
        vector<int> ans;
        while(true){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                if(s.empty()){
                    break;
                }
                root=s.top();
                s.pop();
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};