/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize=2;
    int* res=(int*)malloc(sizeof(int)*2);
    res[0]=res[1]=0;
    int left=0;
    int right=numbersSize-1;
    int sum;
    while(left<right){
        sum=numbers[left]+numbers[right];
        if(sum<target)
            left++;
        else if(sum>target)
            right--;
        else{
            res[0]=left;
            res[1]=right;
            return res;
        }
    }
    return res;
}