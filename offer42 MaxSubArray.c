int maxSubArray(int* nums, int numsSize){
    if(numsSize==0)
        return 0;
    if(numsSize==1)
        return nums[0];
    int i,max,sum;
    max=nums[0];
    sum=0;
    for(i=0;i<numsSize;i++){
        if(sum<=0)
            sum=nums[i];
        else
            sum+=nums[i];
        //要求连续的子数组，那么最后一个nums[i]一定在里面
        max=fmax(sum,max);
    }
    return max;
}