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
    // struct node *q=head->next;
    // i=1;
    // int j=n;
    // while(j>=1){
    //     q=q->next;
    //     i++;
    //     if(i==m-1){
    //         printf("%d,",q->next->val);
    //         q->next=q->next->next;
    //         i=0;
    //         j--;
    //     }
    // }
    // return q->val;

    //while m=2,TIMEOUT!
    int x=0;
    int i=0;
    for(i=2;i<=n;i++)
        x=(x+m)%i;
    return x;
}
