int findNthDigit(int n){
    int digit=1;
    long start=1;
    long count=9;
    while(n>count){
        n=(int)(n-count);
        digit+=1;
        start*=10;
        count=(long)digit*start*9;
    }
    int num=start+(n-1)/digit;
    int index=(n-1)%digit;
    while(index<(digit-1)){
        num/=10;
        digit--;
    }
    return num%10;
}