/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool symmetric(struct TreeNode* left,struct TreeNode* right){
    if(left==NULL && right==NULL)
        return true;
    else if(left!=NULL && right==NULL)
        return false;
    else if(left==NULL && right!=NULL)
        return false;
    else{
        if(left->val!=right->val)
            return false;
        else{
            return symmetric(left->left,right->right)&&symmetric(left->right,right->left);          
        }
    }
}


bool isSymmetric(struct TreeNode* root){
    if(root==NULL)
        return true;
    return symmetric(root->left,root->right);
}