int minSubArrayLen(int target, int* nums, int numsSize){
    int min=999999;
    //记录子数组累加值，最小的次数
    int res=999999;
    int sum=0;
    //初始化双指针，左右指针都从数组头开始
    int left,right;
    left=right=0;
    //右指针不断往右走
    for(;right<numsSize;right++){
        sum+=nums[right];
        //一旦右指针走到累计值满足，左指针开始走，同时记录最小值
        while(left<=right && sum>=target){
            res=fmin(res,right-left+1);
            sum-=nums[left++];
        }
    }
    return res==999999?0:res;
}