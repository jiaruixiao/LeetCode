#define MAXSIZE 2048
typedef struct {
    int *data;
    int front;
    int rear;
} Queue;

/* 定义循环队列 */
typedef struct {
    Queue *dataQue; /* 存储队列数据 */
    Queue *maxQue;  /* 单调队列, 数据递增排列, 此队列为双端队列 */
} MaxQueue;

bool isEmpty(Queue *q) {
    return q->front == q->rear;
}
/* 入队操作, 默认队列足够大, 不会满 */
void enQueue(Queue *q, int x) {
    q->data[q->rear++] = x;
    q->rear %= MAXSIZE;
}
/* 出队操作, 判队列空在函数外实现 */
int deQueue(Queue *q) {
    int x = q->data[q->front++];
    q->front %= MAXSIZE;
    return x;
}

/* 获取队列front元素 */
int getFrontQueue(Queue *q) {
    return q->data[q->front];
}

/* 获取队列rear元素 */
int getRearQueue(Queue *q) {
    int rear = (q->rear - 1 + MAXSIZE) % MAXSIZE; /* 循环队列保护 */
    return q->data[rear];
}

/* 最大队列初始化 */
MaxQueue* maxQueueCreate() {
    MaxQueue *obj       = (MaxQueue*)malloc(sizeof(MaxQueue));
    obj->dataQue        = (Queue*)malloc(sizeof(Queue));
    obj->maxQue         = (Queue*)malloc(sizeof(Queue));
    
    obj->dataQue->data  = (int*)malloc(sizeof(int) * MAXSIZE);
    obj->dataQue->front = 0;
    obj->dataQue->rear  = 0;
    obj->maxQue->data  = (int*)malloc(sizeof(int) * MAXSIZE);
    obj->maxQue->front = 0;
    obj->maxQue->rear  = 0;
    return obj;
}

/* 队列为空, 返回1; 非空时, 返回maxQue的队头 */
int maxQueueMax_value(MaxQueue* obj) {
    if (isEmpty(obj->dataQue)) {
        return -1;
    }
    return getFrontQueue(obj->maxQue);
}

/* 入队操作, dataQue, 数据正常入队 */
/*          maxQue, 从队列尾部往前, 小于val的元素从队尾出队, 最后val入队*/
void maxQueuePush_back(MaxQueue* obj, int value) {
    enQueue(obj->dataQue, value);
    while (!isEmpty(obj->maxQue) && getRearQueue(obj->maxQue) < value) {
        obj->maxQue->rear--;
    }
    enQueue(obj->maxQue, value);
}

/* 出队操作: dataQue, 数据正常出队=x */
/*          maxQue, 当x==maxQue队列的队头时, maxQue出队 */
int maxQueuePop_front(MaxQueue* obj) {
    if (isEmpty(obj->dataQue)) {
        return -1;
    }
    int x = deQueue(obj->dataQue);
    if (x == getFrontQueue(obj->maxQue)) {
        deQueue(obj->maxQue);
    }
    return x;
}
/* 释放空间 */
void maxQueueFree(MaxQueue* obj) {
    free(obj->dataQue->data);
    free(obj->dataQue);
    free(obj->maxQue->data);
    free(obj->maxQue);
    free(obj);
}


/**
 * Your MaxQueue struct will be instantiated and called as such:
 * MaxQueue* obj = maxQueueCreate();
 * int param_1 = maxQueueMax_value(obj);
 
 * maxQueuePush_back(obj, value);
 
 * int param_3 = maxQueuePop_front(obj);
 
 * maxQueueFree(obj);
*/