bool isPalindrome(char * s){
    int len=strlen(s);
    char *q=(char *)malloc(sizeof(char)*(len+1));
    int i,j;
    for(i=0,j=0;i<len;i++)
        if((s[i]>='a'&& s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')){
            if(s[i]>='A' && s[i]<='Z')
                s[i]=s[i]-'A'+'a';
            q[j]=s[i];
            j++;
        }
    q[j]='\0';
    // printf("%s",q);
    int q_len=strlen(q);
    for(i=0;i<q_len/2;i++)
        if(q[i]!=q[q_len-i-1])
            return false;
    
    return true;
}