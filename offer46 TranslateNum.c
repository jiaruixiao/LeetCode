int translateNum(int num){
    // if(num<10)
    //     return 1;
    // int sum;
    // sum=num%100;
    // if(sum<=9||sum>=26)
    //     return translateNum(num/10);
    // else
    //     return translateNum(num/10)+translateNum(num/100);
    
    //recursion
    int a,b,sum;
    a=b=1;
    while(num>9){
        sum=(num%100>=10 && num%100<=25)? a+b:b;
        a=b;
        b=sum;
        num=num/10;
    }
    return b;
}
