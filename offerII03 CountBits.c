/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    *returnSize=n+1;
    int* res=(int *)malloc(sizeof(int)*(n+1));
    res[0]=0;
    for(int i=0;i<n+1;i++){
        res[i]=res[i>>1]+(i&1);
    }
    return res;
}