/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	if(head==NULL)
        return NULL;
    struct Node* q=(struct Node *)malloc(sizeof(struct Node));
    struct Node* p=q;
    struct Node* r=q;
    struct Node* restart=head;
    struct Node* start=head;
    struct Node* origin=head;
    int i;
    while(head){
        p->next=(struct Node *)malloc(sizeof(struct Node));
        p->random=(struct Node *)malloc(sizeof(struct Node));
        p=p->next;
        p->val=head->val;
        head=head->next;
    }
    p->next=NULL;
    p->random=NULL;
    struct Node* p_end=p->next;
    p=q->next;
    while(restart){
        if(restart->random==NULL){
            restart=restart->next;
            p->random=p_end;
            p=p->next;
            continue;
        }
        else{
            r=q->next;
            for(start=origin;restart->random!=start;start=start->next){
                r=r->next;
            }
            p->random=r;
            p=p->next;
            restart=restart->next;

        }
    }
    return q->next;
}