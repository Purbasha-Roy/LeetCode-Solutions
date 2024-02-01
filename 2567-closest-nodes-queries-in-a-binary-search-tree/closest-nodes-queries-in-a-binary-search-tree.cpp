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
vector<int> v;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    vector<int> binarysearch(int x, int low, int high){
        int mini=-1;
        int maxi=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(v[mid]==x){
                return {x,x};
            }
            else if(v[mid]>x){
                maxi=v[mid];
                high=mid-1;
            }
            else{
                mini=v[mid];
                low=mid+1;
            }
        }
        return {mini,maxi};
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);
        vector<vector<int>> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(binarysearch(queries[i],0,v.size()-1));
        }
        return ans;
    }
};