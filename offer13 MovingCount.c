int count(int i,int j,int m,int n,int k,int map[m][n]){
    if(i<0 || i>=m || j<0 || j>=n || (i/10+ i%10+j/10+ j%10)>k ||map[i][j]==1)
        return 0;
    map[i][j]=1;
    return 1+count(i,j+1,m,n,k,map)+count(i,j-1,m,n,k,map)+count(i+1,j,m,n,k,map)+count(i-1,j,m,n,k,map);
}

int movingCount(int m, int n, int k){
    int num=0;
    int map[m][n];
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            map[i][j]=0;

    return count(0,0,m,n,k,map);
}