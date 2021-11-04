/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode* p=(struct ListNode*)malloc(sizeof(struct ListNode));
    p=head;
    // struct ListNode* cur;
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    while(len-k>0){
        p=p->next;
        len--;
    }
    return p;
}