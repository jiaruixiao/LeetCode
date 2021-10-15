int findRepeatNumber(int* nums, int numsSize){
    // int i;
    // int samenum[numsSize];
    // for(i=0;i<numsSize;i++)
    //     samenum[i]=0;
    // for(i=0;i<numsSize;i++){
    //     samenum[nums[i]]++;
    //     if(samenum[nums[i]]>1)
    //         return nums[i];
    // }
    // return -1;
    int i=0;
    int temp;
    while(i<numsSize){
        if(nums[i]==i){
            i++;
            continue;
        }
        if(nums[nums[i]]==nums[i])
            return nums[i];
        temp=nums[i];
        nums[i]=nums[nums[i]];
        nums[temp]=temp;
    }
    return -1;
    //原地交换法
}

