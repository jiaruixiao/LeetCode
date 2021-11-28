int majorityElement(int* nums, int numsSize){
    int x,votes,i;
    x=votes=0;
    for(i=0;i<numsSize;i++){
        if(votes==0)
            x=nums[i];
        votes+=nums[i]==x?1:-1;
    }
    return x;
}
