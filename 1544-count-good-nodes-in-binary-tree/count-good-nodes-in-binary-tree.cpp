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
    void function(TreeNode* node, int current, int& count){
        if(node==NULL) return;
        if(node->val>=current){
            count++;
            current=node->val;
        }
        function(node->left,current,count);
        function(node->right,current,count);
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        function(root,root->val,count);
        return count;
    }
};