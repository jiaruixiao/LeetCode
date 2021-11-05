/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* q=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p=q;
    if(l1==NULL&&l2==NULL)
        return NULL;

    while(l1!=NULL && l2!=NULL){
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        if(l1->val<l2->val){
            p=p->next;
            p->val=l1->val;

            l1=l1->next;
        }
        else{
            p=p->next;
            p->val=l2->val;
            l2=l2->next;
        } 
    }

    if(l1==NULL)
        p->next=l2;
    else
        p->next=l1;
    return q->next;
}