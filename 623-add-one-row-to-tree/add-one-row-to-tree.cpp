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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while(!q.empty() && i<depth-1){
            int size=q.size();
            for(int j=0;j<size;j++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            i++;
        }
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            TreeNode* currleft=current->left;
            TreeNode* currright=current->right;
            current->left=new TreeNode(val,currleft,nullptr);
            current->right=new TreeNode(val,nullptr,currright);
        }
        return root;
    }
};