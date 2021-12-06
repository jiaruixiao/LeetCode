int strToInt(char* str){
    int len,i,sign;
    long num;
    i=num=0;
    sign=1;
    len=strlen(str);
    while(str[i]==' ')
        i++;
    if(str[i]=='-'){
        sign=-1;
        i++;
    }
    else if(str[i]=='+'){
        sign=1;
        i++;
    }
    if(str[i]<'0' || str[i]>'9'){
        return 0;
    }
    for(;(i<len) && (str[i]>='0') && (str[i]<='9');i++){
        num=str[i]-'0'+num*10;
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