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
TreeNode* first;
TreeNode* prev;
TreeNode* middle;
TreeNode* last;
// vector<int> ans;
// void inorder(TreeNode* root){
//     if(root==NULL){
//         return;
//     }
//     inorder(root->left);
//     ans.push_back(root->val);
//     inorder(root->right);
// }
// void inorderhelp(TreeNode* root, vector<int>& res, int& index){
//     if(root==NULL){
//         return;
//     }
//     inorderhelp(root->left,res,index);
//     if(res[index]!=root->val){
//         root->val=res[index];
//     }
//     index++;
//     inorderhelp(root->right,res,index);
// }
void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    if(prev!=NULL && root->val<prev->val){
        if(first==NULL){
            first=prev;
            middle=root;
        }
        else{
            last=root;
        }
    }
    prev=root;
    inorder(root->right);
}
    void recoverTree(TreeNode* root) {
        // METHOD 1
        // inorder(root);
        // vector<int> res(ans);
        // sort(res.begin(),res.end());
        // int index=0;
        // inorderhelp(root,res,index);

        // METHOD 2
        last=first=middle=prev=NULL;
        inorder(root);
        if(first && last){
            swap(first->val,last->val);
        }
        else if(first && middle){
            swap(first->val,middle->val);
        }
    }
};