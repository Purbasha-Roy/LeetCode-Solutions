/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void solved(TreeNode* cloned, TreeNode* target){
        if(cloned==NULL){
            return;
        }
        if(cloned->val==target->val){
            ans=cloned;
        }
        solved(cloned->left,target);
        solved(cloned->right,target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        solved(cloned,target);
        return ans;
    }
};