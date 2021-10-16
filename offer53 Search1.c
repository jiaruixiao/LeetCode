int search(int* nums, int numsSize, int target){
    // int start,end;
    // start=0;
    // end=numsSize-1;
    // while(start<=end){
    //     if(nums[start]<target)
    //         start++;
    //     else if(nums[end]>target)
    //         end--;
    //     else
    //         break;
    // }
    // return end-start+1;
    //双指针法 时间复杂度为O(n)，通过二分法可以优化到O(logn)
    if(numsSize==0)
        return 0;
    int low=0;
    int high=numsSize-1;
    int mid;
    while(low<=high){
        mid=(high+low)/2;
        if(nums[mid]>target)
            high=mid-1;
        else if(nums[mid]<target)
            low=mid+1;
        else{
            if(nums[high]!=target)
                high--;
            else if(nums[low]!=target)
                low++;
            else
                break;
        }
    }
    return high-low+1;
}