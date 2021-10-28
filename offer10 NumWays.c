int numWays(int n){
    if(n==0||n==1)
        return 1;
    int a,b,i;
    a=2;
    b=1;
    for(i=2;i<n;i++){
        a=a+b;
        b=a-b;
        a=a%1000000007;
    }
    return a;
}