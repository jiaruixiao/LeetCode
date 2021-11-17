#define MAX_SIZE 50000

typedef struct PriorQueueTag {
    int capacity;
    int size;
    bool isMin;
    int eles[MAX_SIZE + 1];
} PriorQueue;


typedef struct {
    PriorQueue minHeap;
    PriorQueue maxHeap;
} MedianFinder;

static bool IsPriorQueueEmpty(PriorQueue *queue)
{
    return queue->size == 0;
}

static  bool IsPriorQueueFull(PriorQueue *queue)
{
    return queue->size == queue->capacity;
}

void InitPriorQueue(PriorQueue *queue, bool isMin)
{
    queue->capacity = MAX_SIZE;
    queue->size = 0;
    queue->isMin = isMin;
}

MedianFinder* medianFinderCreate() {
    MedianFinder *obj = (MedianFinder *)malloc(sizeof(MedianFinder));
    if (obj == NULL) {
        return NULL;
    }
    memset(obj, 0, sizeof(MedianFinder));
    InitPriorQueue(&obj->minHeap, true);
    InitPriorQueue(&obj->maxHeap, false);

    return obj;
}

void InsertPriorQueue(PriorQueue *queue, int num)
{
    if (IsPriorQueueFull(queue)) {
        return;
    }

    if (IsPriorQueueEmpty(queue)) {
        queue->eles[1] = num;
        queue->size = 1;
        return;
    }

    queue->eles[++queue->size] = num;
    int i = queue->size;
    int parent;
    for (; i > 1; i = parent) {
        parent = (i >> 1);
        if (queue->isMin) {
            if (num > queue->eles[parent]) {
                break;
            }
        }
        else {
            if (num < queue->eles[parent]) {
                break;
            }
        }

        queue->eles[i] = queue->eles[parent];
    }
    queue->eles[i] = num;
    return;
}

int RemoveTopValFromPriorQueue(PriorQueue *queue)
{
    if (IsPriorQueueEmpty(queue)) {
        return -1;
    }
    int last = queue->eles[queue->size];
    int first = queue->eles[1];
    queue->size--;

    if (IsPriorQueueEmpty(queue)) {
        return first;
    }

    int i = 1;
    int extrIdx = 0;
    for (; i * 2 <= queue->size; i = extrIdx) {
        extrIdx = 2 * i;
        if (queue->isMin) {
            if (extrIdx + 1 <= queue->size && queue->eles[extrIdx] > queue->eles[extrIdx + 1]) {
                extrIdx++;
            }
        } else {
            if (extrIdx + 1 <= queue->size && queue->eles[extrIdx] < queue->eles[extrIdx + 1]) {
                extrIdx++;
            }
        }
        if (queue->isMin) {
            if (last < queue->eles[extrIdx]) {
                break;
            }
        }
        else {
            if (last > queue->eles[extrIdx]) {
                break;
            }
        }

        queue->eles[i] = queue->eles[extrIdx];
    }
    queue->eles[i] = last;
    return first;

}
void medianFinderAddNum(MedianFinder* obj, int num) {
    PriorQueue *minHeap = &obj->minHeap;
    PriorQueue *maxHeap = &obj->maxHeap;

    if (IsPriorQueueEmpty(minHeap) || num >= minHeap->eles[1]) {
        InsertPriorQueue(minHeap, num);
    } else {
        InsertPriorQueue(maxHeap, num);
    }

    int size = minHeap->size + maxHeap->size;
    int k = size / 2;
    if (size % 2 != 0) {
        k++;
    }

    if (minHeap->size > k) {
        while (minHeap->size > k) {
            int temp = RemoveTopValFromPriorQueue(minHeap);
            InsertPriorQueue(maxHeap, temp);
        }
    } else {
        while (maxHeap->size > k) {
            int temp = RemoveTopValFromPriorQueue(maxHeap);
            InsertPriorQueue(minHeap, temp);
        }
    }

    return;
}


double medianFinderFindMedian(MedianFinder* obj) {
    PriorQueue *minHeap = &obj->minHeap;
    PriorQueue *maxHeap = &obj->maxHeap;
    int size = obj->minHeap.size + obj->maxHeap.size;
    if (size % 2 == 0) {
        double leftVal = IsPriorQueueEmpty(maxHeap) ? 0 : maxHeap->eles[1];
        double rightVal = IsPriorQueueEmpty(minHeap) ? 0 : minHeap->eles[1];
        return (leftVal + rightVal) / 2;
    } else {
        if (minHeap->size > maxHeap->size) {
            return (double)minHeap->eles[1];
        } else {
            return (double)maxHeap->eles[1];
        }
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/