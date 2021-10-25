void ReverseTree(struct TreeNode* root){
    if(root!=NULL){
        struct TreeNode* p=root->left;
        root->left=root->right;
        root->right=p;
    }
    if(root->left!=NULL)
        ReverseTree(root->left);
    if(root->right!=NULL)
        ReverseTree(root->right);
}

struct TreeNode* mirrorTree(struct TreeNode* root){
    if(root==NULL)
        return root;
    ReverseTree(root);
    return root;
}