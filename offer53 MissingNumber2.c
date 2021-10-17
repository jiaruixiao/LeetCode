int missingNumber(int* nums, int numsSize){
    int low,high,mid;
    low=0;
    high=numsSize-1;
    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]==mid)
            low=mid+1;
        else 
            high=mid-1;
    }
    return low;
}