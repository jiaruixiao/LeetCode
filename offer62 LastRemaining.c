struct node{
    int val;
    struct node *next;
};

int lastRemaining(int n, int m){
    // struct node *head=(struct node*)malloc(sizeof(struct node));
    // struct node *p=head;
    // int i;
    // for(i=0;i<n;i++){
    //     p->next=(struct node*)malloc(sizeof(struct node));
    //     p=p->next;
    //     p->val=i;
    // }
    // p->next=head->next;
    // p=head->next;
    // struct node *q=(struct node*)malloc(sizeof(struct node));
    // while(p->next!=p){
    //     for(i=1;i<m;i++){
    //         q=p;
    //         p=p->next;
    //     }
    //     q->next=p->next;
    //     free(p);
    //     p=q->next;
    // }
    // return p->val;

    while m=2,TIMEOUT!
    int x=0;
    int i=0;
    for(i=2;i<=n;i++)
        x=(x+m)%i;
    return x;
}