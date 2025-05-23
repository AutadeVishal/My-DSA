class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
             return new TreeNode(val);
               
        }
       else if(root->val<val){
            root->right=insertIntoBST(root->right,val);
        }
        else{
            root->left=insertIntoBST(root->left,val);
        }
        return root;
    }
};
