/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// int n;
// void preorder(struct TreeNode* root,int *num){
//     if(root==NULL)
//         return ;
//     num[n++]=root->val;
//     preorder(root->left,num);
//     preorder(root->right,num);
// }

// int kthLargest(struct TreeNode* root, int k){
//     int i,j,temp;
//     int *num=(int*)malloc(sizeof(int)*10000);
//     for(i=0;i<1000;i++)
//         num[i]=0;
//     n=0;
//     preorder(root,num);
//     for (i=0; i<k; ++i){
//         for (j=0; j<n-1-i; ++j){
//             if (num[j] > num[j+1]){
//                 temp = num[j];
//                 num[j] = num[j+1];
//                 num[j+1] = temp;
//             }
//         }
//     }
//     return num[n-k];
// }

int n;
int res;
void inorder(struct TreeNode* root){
    if(root==NULL)
        return ;
    inorder(root->right);
    if(n==0)
        return ;
    if(--n==0)
        return res=root->val;
    inorder(root->left);
}

int kthLargest(struct TreeNode* root, int k){
    // int *num=(int*)malloc(sizeof(int)*10000);
    // for(i=0;i<1000;i++)
    //     num[i]=0;
    n=k;
    inorder(root);
    return res;
}