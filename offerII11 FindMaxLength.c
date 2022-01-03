int findMaxLength(int* nums, int numsSize){
    if(numsSize==1)
        return 0;
    int map[2*numsSize+1];
    int i;
    int sum=0;
    int res=0;
    for(i=0;i<numsSize*2+1;i++)
        map[i]=-999;
    map[numsSize]=-1;
    for(i=0;i<numsSize;i++){
        if(nums[i]==1)
            sum++;
        else
            sum--;
        if(map[sum+numsSize]==-999)
            map[sum+numsSize]=i;
        else
            res=fmax(res,i-map[sum+numsSize]);
    }
    return res;
}