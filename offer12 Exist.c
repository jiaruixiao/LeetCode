bool dfs(char** board, char* word,int i, int j,int k,int rows,int cols){
    if(i>=rows || i<0 || j>=cols || j<0 || board[i][j]!=word[k])
        return false;
    if(k==strlen(word)-1)
        return true;
    board[i][j]='\0';
    bool res=dfs(board,word,i+1,j,k+1,rows,cols) || dfs(board,word,i-1,j,k+1,rows,cols) || dfs(board,word,i,j+1,k+1,rows,cols) || dfs(board,word,i,j-1,k+1,rows,cols);
    board[i][j]=word[k];
    return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word){
    int i,j;
    for(i=0;i<boardSize;i++)
        for(j=0;j<*boardColSize;j++)
            if(dfs(board,word,i,j,0,boardSize,*boardColSize))
                return true;
    return false;
}
