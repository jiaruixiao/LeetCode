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

int gettop(Stack *s){
    if(!isempty(s)){
        int num=(s->top)-1;
        // s->top++;
        return s->data[num];
    }
    else
        return -1;
}


bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->data=(int*)malloc(sizeof(int)*pushedSize);
    s->top=0;
    int a,i,j;
    j=0;
    for(i=0;i<pushedSize;i++){
        push(s,pushed[i]);
        a=gettop(s);
        while(j<poppedSize && a==popped[j]){
            a=pop(s);
            a=gettop(s);
            j++;
        }
    }
    // printf("%d",s->top);
    if(s->top==0)
        return true;
    return false;
}