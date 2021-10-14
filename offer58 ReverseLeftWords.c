char* reverseLeftWords(char* s, int n){
    int i,len;
    len=strlen(s);
    char q;
    for(i=0;i<n/2;i++){
        q=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=q;
    }
    for(i=n;i<(len+n)/2;i++){
        q=s[i];
        s[i]=s[len-i+n-1];
        s[len-i+n-1]=q;
    }
    for(i=0;i<(len)/2;i++){
        q=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=q;
    }
    return s;
}