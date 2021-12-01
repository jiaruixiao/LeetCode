/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int n=target/2;
    int **res=(int **)malloc(sizeof(int)*n);
    *returnColumnSizes=(int*)malloc(sizeof(int)*n);
    *returnSize=0;
    int l=1;
    int r=2;
    int sum=3;
    int k;
    while(l<r){
        if(sum==target){
            res[*returnSize]=(int*)malloc(sizeof(int)*(r-l+1));
            for(k=l;k<=r;k++){
                res[*returnSize][k-l]=k;
                (*returnColumnSizes)[*returnSize]=r-l+1;
            }
            (*returnSize)++;
            sum=sum-l;
            l++;
        }
        else if(sum<target){
            r++;
            sum=sum+r;
        }
        else{
            sum=sum-l;
            l++;
        }
    }
    return res;
}