char* reverseLeftWords(char* s, int n){
    int len,i,j;
    len=strlen(s);
    j=0;
    char *q=(char *)malloc(sizeof(char)*(len+1));
    for(i=n;i<len;i++){
        q[j++]=s[i];
    }
    for(i=0;i<n;i++){
        q[j++]=s[i];
    }
    q[j]='\0';
    return q;
}