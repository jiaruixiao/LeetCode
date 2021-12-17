/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* printNumbers(int n, int* returnSize){
    int sum=0;
    int i,j;
    for(i=1;i<=n;i++){
        sum=10*sum+9;
    }
    *returnSize=sum;
    int *a=(int *)malloc(sizeof(int)*sum);
    for(i=0;i<sum;i++){
        a[i]=i+1;
    }
    return a;
}