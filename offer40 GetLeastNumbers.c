/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int cmp_int(const void* _a , const void* _b){
//     int* a = (int*)_a;
//     int* b = (int*)_b;
//     return *a - *b;
// }



// int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
//     *returnSize=k;
//     if(k==0)
//         return NULL;
//     // int* res=(int *)calloc(k,sizeof(int));
//     qsort(arr,arrSize,sizeof(int),cmp_int);
//     return arr;
// }
// use qsort in stdlib.h
void QuickSort(int *arr,int left,int right){
    // 子数组长度为 1 时终止递归
    if(left>=right)
        return ;
    // 哨兵划分操作（以 arr[l] 作为基准数）
    int i=left;
    int j=right;
    int temp;
    while(i<j){
        while(i<j && arr[j]>=arr[left])
            j--;
        while(i<j && arr[i]<=arr[left])
            i++;
        
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    temp=arr[i];
    arr[i]=arr[left];
    arr[left]=temp;
    // 递归左（右）子数组执行哨兵划分
    QuickSort(arr,left,i-1);
    QuickSort(arr,i+1,right);
}


int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    *returnSize=k;
    if(k==0)
        return NULL;
    QuickSort(arr,0,arrSize-1);
    return arr;
}

