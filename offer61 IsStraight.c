bool isStraight(int* nums, int numsSize){
    int i;
    int max=0;
    int min=999;
    int map[15];
    memset(map,0,sizeof(map));
    for(i=0;i<numsSize;i++){
        if(nums[i] && map[nums[i]]>=1)
            return false;
        map[nums[i]]++;
        if(nums[i]!=0){
            max=fmax(max,nums[i]);
            min=fmin(min,nums[i]);
        }
    }

    return max-min<=4? true:false;
}