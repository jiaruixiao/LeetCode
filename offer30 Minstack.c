typedef struct {
    int *data;
    int top;
}Stack;

typedef struct {
    Stack *a;
    Stack *b;
} MinStack;

/** initialize your data structure here. */

int isEmpty(Stack *s){
    if(s->top==0)
        return 1;
    else
        return 0;
}

void push(Stack *s,int val){
    s->data[s->top++]=val;
}

int pop(Stack *s){
    if(isEmpty(s))
        return -1;
    else
        return s->data[--s->top];
}

MinStack* minStackCreate() {
    MinStack *s;
    s=(MinStack *)malloc(sizeof(MinStack));
    s->a=(Stack *)malloc(sizeof(Stack));
    s->b=(Stack *)malloc(sizeof(Stack));
    s->a->data=(int *)malloc(sizeof(int)*10000);
    s->b->data=(int *)malloc(sizeof(int)*10000);
    s->a->top=s->b->top=0;
    return s;
}

void minStackPush(MinStack* obj, int x) {
    push(obj->a,x);
    if(obj->b->top==0)
        push(obj->b,x);
    else{
        if(x<=obj->b->data[obj->b->top-1])
            push(obj->b,x);
    }
}

void minStackPop(MinStack* obj) {
    int val=pop(obj->a);
    if(obj->b->data[obj->b->top-1]==val)
        pop(obj->b);
}


int minStackTop(MinStack* obj) {
    return obj->a->data[obj->a->top-1];
}

int minStackMin(MinStack* obj) {
    return obj->b->data[obj->b->top-1];
}

void minStackFree(MinStack* obj) {
    free(obj->a->data);
    free(obj->b->data);
    free(obj->a);
    free(obj->b);
    free(obj);
}


/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackMin(obj);
 
 * minStackFree(obj);
*/