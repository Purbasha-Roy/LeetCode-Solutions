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
    bool isEvenOddTree(TreeNode* root) {
        bool even=true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            TreeNode* prev=q.front();
            q.pop();

            if(even && prev->val%2==0) return false;
            if(!even && prev->val%2!=0) return false;

            if(prev->left) q.push(prev->left);
            if(prev->right) q.push(prev->right);

            for(int i=1;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                if(even && (curr->val%2==0 || prev->val>=curr->val)) return false;
                if(!even && (curr->val%2!=0 || prev->val<=curr->val)) return false;

                prev=curr;
            }
            even=!even;
        }
        return true;
    }
};