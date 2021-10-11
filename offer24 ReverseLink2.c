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


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode* q=(struct ListNode *)malloc(sizeof(struct ListNode));;
    struct ListNode* p=q;
    Stack *s;
    s=(Stack *)malloc(sizeof(Stack));
    s->data=(int *)malloc(sizeof(int)*5000);
    s->top=0;
    while(head){
        push(s,head->val);
        head=head->next;
    }
    while(!isempty(s)){
        p->next=(struct ListNode *)malloc(sizeof(struct ListNode));
        p=p->next;
        p->val=pop(s);     
    }
    p->next=NULL;
    return q->next;
    // struct ListNode* returnhead=NULL;
    // while(head){
    //     struct ListNode* node=head;
    //     head=head->next;
    //     node->next=returnhead;
    //     returnhead=node;
    // }
    // return returnhead;

}