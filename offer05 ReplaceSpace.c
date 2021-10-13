char* replaceSpace(char* s){
    char *p=(char *)malloc(sizeof(char)*10001);
    int i,j,len;
    len=strlen(s);
    j=0;
    for(i=0;i<len;i++){
        if(s[i]==' '){
            p[j]='%';
            p[j+1]='2';
            p[j+2]='0';
            j=j+3;
        }
        else{
            p[j]=s[i];
            j++;
        }
    }
    p[j]='\0';
    return p;
}