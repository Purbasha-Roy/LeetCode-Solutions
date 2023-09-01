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
    TreeNode* helper(vector<int>& inorder,int instart, int inend, vector<int> postorder, int poststart, int postend, unordered_map<int,int>& mp){
        if(instart>inend || poststart>postend){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[postend]);
        int start=mp[root->val];
        int size=start-instart;
        root->left=helper(inorder,instart,start-1,postorder,poststart,poststart+size-1,mp);
        root->right=helper(inorder,start+1,inend,postorder,poststart+size,postend-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()){
            return NULL;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
        return root;
    }
};