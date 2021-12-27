int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    if(k<2)
        return 0;
    int res=0;
    int sum=1;
    //初始化双指针，左右指针都从数组头开始
    int left,right;
    left=right=0;
    //右指针不断往右走
    while(right<numsSize){
        sum*=nums[right];
        while(sum>=k)
            sum/=nums[left++];
        res+=right-left+1;
        right++;
    }
    return res;
}