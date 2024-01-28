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
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL) continue;
            q.push(temp->left);
            q.push(temp->right);
            ans.push_back(temp->left);
            ans.push_back(temp->right);
        }
        int count=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==NULL) count=1;
            else if(count==1) return false;
        }
        return true;
    }
};