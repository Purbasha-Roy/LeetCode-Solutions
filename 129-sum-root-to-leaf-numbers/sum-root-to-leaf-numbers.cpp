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
    void dfstraversal(TreeNode* root, int &number){
        if(root==NULL){
            return;
        }
        number=number*10+(root->val);
        if(root->left==NULL && root->right==NULL){
            ans+=number;
        }
        dfstraversal(root->left,number);
        dfstraversal(root->right,number);
        number/=10;
    }
    int sumNumbers(TreeNode* root) {
        int number=0;
        dfstraversal(root,number);
        return ans;
    }
};