char* reverseWords(char* s){
    int i,len;
    len=strlen(s);
    if(len==0)
        return "";
    int w=0;
    int top=-1;
    char *res=(char *)calloc((len+1),1);
    char *stack=(char *)calloc((len+1),1);
    for(i=len-1;i>=0;i--){
        if(s[i]==' '){
            while(top>=0){
                res[w++]=stack[top--];
            }
            if(w>0 && res[w-1]!=' ')
                res[w++]=' ';
        }
        else{
            top++;
            stack[top]=s[i];
        }
    }
    while(top>=0){
        res[w++]=stack[top--];
    }
    len=strlen(res);
    while(len>0 && res[len-1]==' '){
        res[len-1]='\0';
        len--;
    }
    return res;
}