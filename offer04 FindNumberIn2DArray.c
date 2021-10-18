bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){

    // if(matrixSize==0||*matrixColSize==0)
    //     return false;
    // if(target<matrix[0][0]||target>matrix[matrixSize-1][*matrixColSize-1])
    //     return false;
    // int low,high,mid,i;
    // for(i=0;i<matrixSize;i++){
    //     if(target<matrix[i][0]||target>matrix[i][*matrixColSize-1])
    //         continue;
    //     else{
    //         low=0;high=*matrixColSize-1;
    //         while(low<=high){
    //             mid=(low+high)/2;
    //             if(matrix[i][mid]>target)
    //                 high=mid-1;
    //             else if(matrix[i][mid]<target)
    //                 low=mid+1;
    //             else
    //                 return true;
    //         }
    //     }
    // }
    // return false;
    // 时间复杂度O(mlogn),此题不适用于二分搜索
    if(matrixSize==0||*matrixColSize==0)
        return false;
    if(target<matrix[0][0]||target>matrix[matrixSize-1][*matrixColSize-1])
        return false;
    int row=matrixSize-1;
    int col=0;
    while(row>=0 && col<*matrixColSize){
        if(target<matrix[row][col])
            row--;
        else if(target>matrix[row][col])
            col++;
        else
            return true;
    }
    return false;
    //时间复杂度O(m+n)
}


