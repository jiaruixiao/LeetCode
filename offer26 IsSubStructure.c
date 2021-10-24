/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSame(struct TreeNode* A,struct TreeNode* B){
    if(A==NULL && B==NULL)
        return true;
    else if(A!=NULL && B==NULL)
        return true;
    else if(A==NULL  && B!=NULL)
        return false;
    else if(A->val!=B->val)
        return false;
    
    return isSame(A->left,B->left) && isSame(A->right,B->right);
}

bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
    if(A==NULL || B==NULL)
        return false;
    struct TreeNode* p=A;
    if(isSame(A,B)){
        printf("1\n");
        return true;
    }   
    return isSubStructure(A->left,B)||isSubStructure(A->right,B);
}


