int fib(int n){
    // if(n==0)
    //     return 0;
    // else if(n==1)
    //     return 1;
    // else if(n==2)
    //     return 1;
    // else{
    //     return fib(n-1)+fib(n-2);
    // }
    // recursion, time out!
    if(n==0||n==1)
        return n;
    int a,b,i;
    a=1;
    b=0;
    for(i=1;i<n;i++){
        a=a+b;
        b=a-b;
        a%=1000000007;
    }
    return a;
}