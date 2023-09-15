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
void rightview(TreeNode* root, int level, vector<int>& ans){
    if(root==NULL){
        return;
    }
    if(ans.size()==level){
        ans.push_back(root->val);
    }
    rightview(root->right,level+1,ans);
    rightview(root->left,level+1,ans);
}
    vector<int> rightSideView(TreeNode* root) {
        // METHDO 1
        // vector<int> v;
        // if(root==NULL){
        //     return v;
        // }
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int size=q.size();
        //     for(int i=0;i<size;i++){
        //         TreeNode* node=q.front();
        //         q.pop();
        //         if(i==size-1){
        //             v.push_back(node->val);
        //         }
        //         if(node->left){
        //             q.push(node->left);
        //         }
        //         if(node->right){
        //             q.push(node->right);
        //         }
        //     }
        // }
        // return v;

        // METHOD 2
        vector<int> v;
        rightview(root,0,v);
        return v;

    }
};