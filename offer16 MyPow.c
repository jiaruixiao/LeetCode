double myPow(double x, int n){
    if(n==0)
        return 1;
    long b=n;
    double res=1.0;
    if(b<0){
        x=1/x;
        b=-b;
    }
    while(b>0){
        if((b&1)==1)
            res=res*x;
        x*=x;
        b>>=1;
    }
    return res;
}
