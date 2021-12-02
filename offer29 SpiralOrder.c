/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize==0){
        *returnSize=0;
        return NULL;
    }
    *returnSize=matrixSize*(*matrixColSize);
    int* res=(int *)malloc(sizeof(int)*(*returnSize+1));
    // *returnSize=len;
    int temp[matrixSize][*matrixColSize];
    int i,j;
    for(i=0;i<matrixSize;i++)
        for(j=0;j<*matrixColSize;j++)
            temp[i][j]=1;
    int x=0;
    int y=0;
    char flag='1';
    for(i=0;i<*returnSize;i++){
        res[i]=matrix[x][y];
        temp[x][y]=-1;
        if(flag=='1'){
            if(y<(*matrixColSize)-1 && temp[x][y+1]!=-1)
                y++;
            else{
                x++;
                flag='2';
            }
        }
        else if(flag=='2'){
            if(x<matrixSize-1 && temp[x+1][y]!=-1)
                x++;
            else{
                y--;
                flag='3';
            }
        }
        else if(flag=='3'){
            if(y>0 && temp[x][y-1]!=-1)
                y--;
            else{
                x--;
                flag='4';
            }
        }
        else if(flag=='4'){
            if(x>0 && temp[x-1][y]!=-1)
                x--;
            else{
                y++;
                flag='1';
            }
        }
    }
    return res;
}
