int **ret;          // 用来建立一个指向路径的 指针数组 指向各个路径数组的首地址
int retSize;        //记录当前指针数组的最一个路径的后一个节点用来添加路径
int *retColSize;    //记录对应 i 号路径的长度
int *path;          //记录当前路径上的节点
int pathSize;       //记录路径长度

void preOrder(struct TreeNode * root, int target){
    if(root == NULL){
          return;
    }
    path[pathSize++] = root->val;
    target = target - root->val;
    //如果此时 root是叶子节点 并且 target 值为0 说明满足和为target
    if(root->right == NULL && root->left == NULL && target == 0){
        int *temp = (int *)malloc(sizeof(int)*pathSize);
        for(int i = 0 ; i < pathSize ;i++){
            temp[i] = path[i];
        }
        ret[retSize] = temp;
        retColSize[retSize++] = pathSize; 
    }
    preOrder(root->left, target);
    preOrder(root->right, target);
    pathSize--; //遍历完该节点后对路径长度减一 回溯

}
int** pathSum(struct TreeNode* root, int target, int* returnSize, int** returnColumnSizes){
    ret = malloc(sizeof(int*) * 2001);
    retColSize = malloc(sizeof(int) * 2001);
    path = malloc(sizeof(int) * 2001);
    retSize = pathSize = 0;
    preOrder(root, target);
    *returnColumnSizes = retColSize;
    *returnSize = retSize;
    return ret;

}