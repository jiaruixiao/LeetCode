#define MAXSIZE 1000

typedef struct{
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
    if(s->top==MAXSIZE)
        return;
    else{
        s->data[s->top]=val;
        s->top++;
    }
}

int pop(Stack *s){
    if(!isempty(s))
        return s->data[--s->top];
    else
        return -1;
}

typedef struct {
    Stack *a;
    Stack *b;
} CQueue;


CQueue* cQueueCreate() {
    CQueue *obj=(CQueue*)malloc(sizeof(CQueue));
    obj->a=(Stack*)malloc(sizeof(Stack));
    obj->a->data=(int *)malloc(MAXSIZE*sizeof(int));
    obj->b=(Stack*)malloc(sizeof(Stack));
    obj->b->data=(int *)malloc(MAXSIZE*sizeof(int));
    obj->a->top=obj->b->top=0;
    return obj;
}

void cQueueAppendTail(CQueue* obj, int value) {
    push(obj->a,value);
}

int cQueueDeleteHead(CQueue* obj) {
    if(!isempty(obj->b))
        return pop(obj->b);
    else{
        if(isempty(obj->a)){
            return -1;
        }
        else{
            int temp;
            while(!isempty(obj->a)){
                temp=pop(obj->a);
                push(obj->b,temp);
            }
            return pop(obj->b);
        }
    }
}

void cQueueFree(CQueue* obj) {
    free(obj->a->data);
    free(obj->b->data);
    free(obj->a);
    free(obj->b);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/