/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA==NULL || headB==NULL)
        return NULL;
    struct ListNode* n1=headA;
    struct ListNode* n2=headB;
    while(n1!=n2){
        n1=(n1==NULL)? headB:n1->next;
        n2=(n2==NULL)? headA:n2->next;
    }
    return n1;
}