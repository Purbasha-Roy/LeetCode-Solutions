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
vector<int> s;
void findsum(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        int sum=0;
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            sum+=node->val;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        s.push_back(sum);
    }
}
TreeNode* update(TreeNode* root){
    int level=0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr=q.front();
            q.pop();
            int sum=(curr->left ? curr->left->val : 0) + (curr->right ? curr->right->val : 0);
            if(level==0){
                curr->val=0;
            }
            if(curr->left){
                q.push(curr->left);
                curr->left->val=s[level+1]-sum;
            }
            if(curr->right){
                q.push(curr->right);
                curr->right->val=s[level+1]-sum;
            }
        }
        level++;
    }
    return root;
}
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        findsum(root);
        return update(root);
    }
};