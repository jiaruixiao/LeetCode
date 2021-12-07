/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    // if(numsSize==0){
    //     *returnSize=0;
    //     return NULL;
    // }
    // *returnSize=numsSize+1-k;
    // if(k==1)
    //     return nums;
    
    // int* res=(int *)calloc(*returnSize,sizeof(int));
    // int i,j,cur;
    // for(i=0;i<*returnSize;i++){
    //     res[i]=nums[i];
    //     for(cur=i;cur<i+k;cur++){
    //         res[i]=(nums[cur]>res[i])?nums[cur]:res[i];
    //     }
    // }
    // return res;

    // time complexity is O(n*k)
    if(numsSize==0){
        *returnSize=0;
        return NULL;
    }
    *returnSize=numsSize+1-k;
    int* queue=(int *)malloc(sizeof(int)*numsSize);
    int* res=(int *)malloc(sizeof(int)*(*returnSize));
    int i,j,front,rear;
    front=rear=0;
    for(i=0;i<k;i++){
        while(rear!=front && nums[queue[rear-1]]<=nums[i])
            rear--;
        queue[rear++]=i;
    }
    res[0]=nums[queue[front]];
    j=1;
    for(i=k;i<numsSize;i++){
        // 如果队头下标已经过期, 则弹出
        while(front!=rear && i-queue[front]>=k)
            front++;
        // 将队列中所有比当前值小的弹出
        while(front!=rear && nums[queue[rear-1]]<=nums[i])
            rear--;
        queue[rear++]=i;
        res[j++]=nums[queue[front]];
    }
    return res;
}