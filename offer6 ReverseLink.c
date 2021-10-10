/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct {
    int *data;
    int top;
}Stack;

int isempty(Stack *s){
    if(s->top==0)
        return 1;
    else
        return 0;
}
void push(Stack *s,int val){
    s->data[s->top++]=val;
}

int pop(Stack *s){
    if(!isempty(s))
        return s->data[--s->top];
    else
        return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
    Stack *s;
    s=(Stack *)malloc(sizeof(Stack));
    s->data=(int *)malloc(sizeof(int)*10000);
    s->top=0;
    while(head){
        push(s,head->val);
        head=head->next;
    }
    
    int *res=(int*)malloc(sizeof(int)*(s->top));
    int i;
    for(i=0;i<s->top;i++)
        res[i]=0;
    (*returnSize)=i;
    i=0;
    while(!isempty(s)){
        res[i]=pop(s);
        i++;
    }
    return res;
}

