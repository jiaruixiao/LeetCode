/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/* 创建队列 */
typedef struct TreeNode* ElemType;
typedef struct QNode{
    ElemType val;
    struct QNode *next;
}QNode;

typedef struct Queue {
    QNode *front;
    QNode *rear;
}LinkQueue;

//
void initQueue(LinkQueue *Q){
    Q->front=(QNode *)malloc(sizeof(QNode));
    Q->front->next=NULL;
    Q->rear=Q->front;
}
//
void enQueue(LinkQueue *Q, ElemType e) {
    QNode *p=(QNode *)malloc(sizeof(QNode));
    p->val=e;
    p->next=NULL;

    Q->rear->next=p;
    Q->rear=p;
}
//
ElemType deQueue(LinkQueue *Q){
    ElemType e;
    QNode* p;

    if(Q->front==Q->rear) return NULL;

    p=Q->front->next;
    e=p->val;
    Q->front->next=p->next;

    if(Q->rear==p) Q->rear=Q->front;
    free(p);

    return e;
}
int getnumQueue(LinkQueue *Q){
    int num;
    num=0;
    QNode* p=Q->front;
    while(Q->front!=Q->rear){
        num++;
        Q->front=Q->front->next;
    }
    Q->front=p;
    return num;
}

// 
void destroyQueue(LinkQueue *Q) {
    while(Q->front){
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
}


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **res=(int **)malloc(sizeof(int*)*1000);
    LinkQueue *Q=(LinkQueue* )malloc(sizeof(LinkQueue));
    returnColumnSizes[0]=(int *)malloc(sizeof(int)*1000);
    struct TreeNode* p;
    *returnSize=0;
    if(root==NULL){
        return NULL;
    }
    initQueue(Q);
    enQueue(Q,root);
    int num=0;
    int i;
    while(Q->front!=Q->rear){
        num=getnumQueue(Q);
        res[*returnSize]=(int *)malloc(sizeof(int)*(num));
        returnColumnSizes[0][*returnSize]=num;
        for(i=0;i<num;i++){
            p=deQueue(Q);
            res[*returnSize][i]=p->val;
            if(p->left)
                enQueue(Q,p->left);
            if(p->right)
                enQueue(Q,p->right);      
        }  
        (*returnSize)++;
    }
    destroyQueue(Q);
    return res;
}