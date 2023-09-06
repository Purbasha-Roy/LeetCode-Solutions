/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(root==NULL){
            return s;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL){
                s.append("#,");
            }
            else{
                s.append(to_string(node->val)+',');
            }
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* builtTree(queue<string> &q){
        string s=q.front();
        q.pop();
        TreeNode* root=new TreeNode(stoi(s));
        queue<TreeNode*> q1;
        q1.push(root);
        while(!q1.empty()){
            TreeNode* curr=q1.front();
            q1.pop();
            s=q.front();
            q.pop();
            if(s!="#"){
                curr->left=new TreeNode(stoi(s));
                q1.push(curr->left);
            }
            else{
                curr->left=NULL;
            }
            s=q.front();
            q.pop();
            if(s!="#"){
                curr->right=new TreeNode(stoi(s));
                q1.push(curr->right);
            }
            else{
                curr->right=NULL;
            }
        }
        return root;
    }
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        queue<string> q;
        string s="";
        for(auto c:data){
            if(c==','){
                q.push(s);
                s="";
            }
            else{
                s+=c;
            }
        }
        return builtTree(q);        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));