int subarraySum(int* nums, int numsSize, int k){
    int res=0;
    int map[numsSize];
    memset(map,0,sizeof(map));
    map[0]=nums[0];
    int i;
    for(i=1;i<numsSize;i++){
        map[i]=map[i-1]+nums[i];
    }
    int temp=0;
    for(i=0;i<numsSize;i++){
        if(map[i]==k)
            res++;
        temp=map[i]-k;
        for(int j=0;j<i;j++)
            if(map[j]==temp)
                res++;
    }
    return res;
}