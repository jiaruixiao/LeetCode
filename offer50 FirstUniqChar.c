char firstUniqChar(char* s){
    int len=strlen(s);
    if(len==0)
        return ' ';
    if(len==1)
        return s[0];
    int map[26];
    int i,j;
    for(i=0;i<26;i++){
        map[i]=0;
    }
    // for(i=0;i<len;i++){
    //     if(map[s[i]-'a']>0)
    //         continue;
    //     for(j=i+1;j<len;j++){
    //         if(s[i]==s[j]){
    //             map[s[i]-'a']++;
    //             break;
    //         }
    //     }
    //     if(map[s[i]-'a']==0)
    //         return s[i];
    // }
    // return ' ';
    for(i=0;i<len;i++)
        map[s[i]-'a']++;
    for(i=0;i<len;i++)
        if(map[s[i]-'a']==1)
            return s[i];
    return ' ';
}