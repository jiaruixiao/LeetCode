/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int a,b;
    int sum;
    int *res=(int *)malloc(sizeof(int)*2);
    a=0,b=numsSize-1;
    while(a<b){
        sum=nums[a]+nums[b];
        if(sum==target){
            res[0]=nums[a];
            res[1]=nums[b];
            *returnSize=2;
            return res;
        }
        else if(sum>target)
            b--;
        else
            a++;
    }
    *returnSize=0;
    return NULL;
}