char * convert(char * s, int numRows){
    if(numRows==1)
        return s;
    int len,batch,i,k,j,line;
    len=strlen(s);
    if(numRows>=len)
        return s;
    char *p;
    j=0;
    p=(char *)malloc((len+1)*sizeof(char));
    for(i=0;i<len;i++){
        k=i%(2*numRows-2);
        if(k==0 ){
            p[j]=s[i];
            j++;
        }
    }
    for(line=1;line<numRows-1;line++){
        for(i=0;i<len;i++){
            k=i%(2*numRows-2);
            if( ((k==line) && (k<=numRows-1)) || ((k>numRows-1) &&(2*numRows-2-k==line))){
                p[j]=s[i];
                j++;
            } 
        }
    }
    for(i=0;i<len;i++){
        k=i%(2*numRows-2);
        if(k==numRows-1 ){
            p[j]=s[i];
            j++;
        }
    }
    p[len]='\0';
    return p;
}