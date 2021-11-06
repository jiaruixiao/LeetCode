/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(int* nums, int numsSize, int* returnSize){
    // int i,odd_num,even_num;
    // odd_num=0;
    // for(i=0;i<numsSize;i++)
    //     if(nums[i]%2==1)
    //         odd_num++;
    // even_num=odd_num;
    // odd_num--;
    // int* res=(int*)malloc(sizeof(int)*(numsSize));
    // for(i=0;i<numsSize;i++)
    //     res[i]=0;
    // for(i=0;i<numsSize;i++){
    //     if(nums[i]%2==0){
    //         res[even_num]=nums[i];
    //         even_num++;
    //     }
    //     else{
    //         res[odd_num]=nums[i];
    //         odd_num--;
    //     }
    // }
    // *returnSize=numsSize;
    // return res;
    // too slow!
    *returnSize=numsSize;
    int i,j,temp;
    i=0;
    j=numsSize-1;
    while(i<=j){
        if(nums[i]%2==0&&nums[j]%2==1){
            temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
        else if(nums[i]%2==1)
            i++;
        else if(nums[j]%2==0)
            j--;
    }
    return nums;
    // double point
}