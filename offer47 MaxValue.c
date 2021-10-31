int maxValue(int** grid, int gridSize, int* gridColSize){
    if(grid==NULL)
        return 0;
    int i,j;
    for(i=0;i<gridSize;i++){
        for(j=0;j<*gridColSize;j++){
            if(i==0 && j==0)
                continue;
            if(i==0)
                grid[i][j]+=grid[i][j-1];
            else if(j==0)
                grid[i][j]+=grid[i-1][j];
            else
                grid[i][j]+=fmax(grid[i][j-1],grid[i-1][j]);
        }
    }
    return grid[i-1][j-1];
    
}