/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
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
// 
void destroyQueue(LinkQueue *Q) {
    while(Q->front){
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
}

int* levelOrder(struct TreeNode* root, int* returnSize){
    int *res=malloc(1009*sizeof(int));
    LinkQueue *Q=(LinkQueue* )malloc(sizeof(LinkQueue));
    struct TreeNode* p;

    *returnSize=0;
    if(root==NULL){
        return NULL;
    }

    initQueue(Q);
    enQueue(Q,root);

    while(Q->front!=Q->rear) {
        if(p=deQueue(Q)) {
            res[*returnSize]=p->val;
            (*returnSize)++;

            enQueue(Q,p->left);
            enQueue(Q,p->right);
        }
    }
    destroyQueue(Q);
    return res;
}