/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *result=(struct ListNode*)malloc(sizeof(struct ListNode ));
    struct ListNode *p=result;
    if(l1->val==0&&l1->next==NULL){
        return l2;
    }
    else if(l2->val==0&&l2->next==NULL){
        return l1;
    }
    else{
        int tag=0;
        int num=0;
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL&&l2!=NULL){
                p->next=(struct ListNode *)malloc(sizeof(struct ListNode));
                p=p->next;
                num=l1->val+l2->val;
                if(tag==1){
                    num=num+1;
                    tag=0;
                }
                if(num>9){
                    tag=1;
                    num=num-10;
                }
                p->val=num;
                num=0;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1!=NULL){
                p->next=(struct ListNode *)malloc(sizeof(struct ListNode));
                p=p->next;
                if(tag==1){
                    p->val=l1->val+tag;
                    tag=0;
                }
                else
                    p->val=l1->val;
                if(p->val>9){
                    tag=1;
                    p->val=p->val-10;
                }
                l1=l1->next;
            }
            else if(l2!=NULL){
                p->next=(struct ListNode *)malloc(sizeof(struct ListNode));
                p=p->next;
                if(tag==1){
                    p->val=l2->val+tag;
                    tag=0;
                }
                else
                    p->val=l2->val;
                if(p->val>9){
                    tag=1;
                    p->val=p->val-10;
                }
                l2=l2->next;
            }
        }
        if(tag==1){
            p->next=(struct ListNode *)malloc(sizeof(struct ListNode));
            p=p->next;
            p->val=1;
        }
        p->next=NULL;
        return result->next;
    }
}