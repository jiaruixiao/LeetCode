int res;

int sumNums(int n){
    res=0;
    bool x=(n>1 && sumNums(n-1)>0);
    res=res+n;
    return res;
}