/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if(preorderSize==0||!preorder)
        return NULL;
    int left_len=0;
    struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val=preorder[0];
    while(left_len<=preorderSize){
        if(preorder[0]==inorder[left_len])
            break;
        left_len++;
    }
    node->left=buildTree(preorder+1,left_len,inorder,left_len);
    node->right=buildTree(preorder+1+left_len,preorderSize-1-left_len,inorder+1+left_len,preorderSize-1-left_len);
    return node;
}