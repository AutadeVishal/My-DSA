void inorder(BinaryTreeNode * &root,vector<BinaryTreeNode *>&v){
	if(!root) return;
	inorder(root->left,v);
	v.push_back(root);
inorder(root->right,v);
}
void preorder(vector<BinaryTreeNode *>v,int &index,int &size){
	if(index>=size){
return;
	} 
BinaryTreeNode * root=v[index];
root->left=nullptr;
root->right=nullptr;
int currindex=index;
index++;
	if(currindex*2+1<size){
	
	root->left=v[index];
preorder(v,index,size);
	}
	if(currindex*2+2<size){
		root->right=v[index];
	preorder(v,index,size);
	;
	}
	return;

}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
vector<BinaryTreeNode *>v;
inorder(root,v);
int index=0;
int size=v.size();
preorder(v,index,size);
return v[0];
}
