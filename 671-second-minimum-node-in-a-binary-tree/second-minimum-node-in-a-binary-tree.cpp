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
set<int> s;
void helper(TreeNode* root){
    if(root==NULL){
        return;
    }
    s.insert(root->val);
    helper(root->left);
    helper(root->right);
}
    int findSecondMinimumValue(TreeNode* root) {
        helper(root);
        if(s.size()<2){
            return -1;
        }
        int i=1;
        for(auto it:s){
            if(i==2){
                return it;
            }
            i++;
        }
        return -1;
    }
};