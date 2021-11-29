/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructArr(int* a, int aSize, int* returnSize){
    *returnSize=aSize;
    if(aSize==0)
        return NULL;
    int* res=(int *)malloc(sizeof(int)*aSize);
    res[0]=1;
    int i;
    int temp=1;
    for(i=1;i<aSize;i++){
        res[i]=res[i-1]*a[i-1];
    }
    for(i=aSize-2;i>=0;i--){
        temp*=a[i+1];
        res[i]*=temp;
    }
    return res;
}
