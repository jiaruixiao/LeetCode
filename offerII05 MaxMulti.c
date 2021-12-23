int IsSame(char *s1,char *s2){
    int len1=strlen(s1);
    int len2=strlen(s2);
    int map[26];
    int i;
    for(i=0;i<26;i++)
        map[i]=0;
    for(i=0;i<len1;i++){
        map[s1[i]-'a']++;
    }
    for(i=0;i<len2;i++){
        if(map[s2[i]-'a']>0)
            return 0;
    }
    return 1;
}

int maxProduct(char ** words, int wordsSize){
    int i,j;
    int max=0;
    for(i=0;i<wordsSize-1;i++)
        for(j=i+1;j<wordsSize;j++){
            if(IsSame(words[i],words[j])){
                int len1=strlen(words[i]);
                int len2=strlen(words[j]);
                max=fmax(max,len1*len2);
            }          
        }
    return max;
}