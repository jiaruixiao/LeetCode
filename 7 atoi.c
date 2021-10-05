int myAtoi(char * s){
    int len,i,sign;
    long num;
    i=num=0;
    sign=1;
    len=strlen(s);
    while(s[i]==' ')
        i++;
    if(s[i]=='-'){
        sign=-1;
        i++;
    }
    else if(s[i]=='+'){
        sign=1;
        i++;
    }
    if(s[i]<'0' || s[i]>'9'){
        return 0;
    }
    for(;(i<len) && (s[i]>='0') && (s[i]<='9');i++){
        num=s[i]-'0'+num*10;
        if(num>=2147483648)
            break;
    }
    num=num*sign;
    if(num>=2147483648)
        num=2147483647;
    else if(num<-2147483648)
        num=-2147483648;
    return num;
}