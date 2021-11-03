/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    // if(head->val==val)
    //     return head->next;
    // struct ListNode *p=head;
    // while(head!=NULL){
    //     if(head->next==NULL)
    //         head=head->next;
    //     else{
    //         if(head->next->val==val){
    //             head->next=head->next->next;
    //         }
    //         else
    //             head=head->next;
    //     }
    // }
    // return p;
    
    if(head->val==val)
        return head->next;
    struct ListNode* p=head;
    struct ListNode* cur=head->next;
    while(cur!=NULL &&cur->val!=val){
        p=cur;
        cur=cur->next;
    }
    if(cur!=NULL)
        p->next=cur->next;
    return head;
    //double point
}
