int maxDepth(struct TreeNode* root){
    if(root==NULL)
        return 0;
    return 1+fmax(maxDepth(root->left),maxDepth(root->right));
}

bool isBalanced(struct TreeNode* root){
    if(root==NULL)
        return true;
    if(abs(maxDepth(root->left)-maxDepth(root->right))>1)
        return false;
    else
        return isBalanced(root->left)&&isBalanced(root->right);
}