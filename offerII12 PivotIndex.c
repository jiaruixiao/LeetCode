int pivotIndex(int* nums, int numsSize){
    int sum,pre,i;
    sum=pre=0;
    for(i=0;i<numsSize;i++)
        sum+=nums[i];
    for(i=0;i<numsSize;i++){
        if(pre*2+nums[i]==sum)
            return i;
        pre+=nums[i];
    }
    return -1;
}