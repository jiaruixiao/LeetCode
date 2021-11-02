int lengthOfLongestSubstring(char* s){
    int len=strlen(s);
    if(len==0||len==1)
        return len;
    int i,j,max;
    int map[128];
    //存储每个字符最后出现的位置
    max=0;
    for(j=0;j<128;j++)
        map[j]=-1;
    j=0;
    for(i=0;i<len;i++){
        if(map[s[i]]<j)     //前面的子串不含新加的字符
            max=fmax(max,i-j+1);
        else    //当前字符在之前的子串中出现过   
            j=map[s[i]]+1;  //更新i，使得i到j没有重复字符
        map[s[i]]=i;    //更改当前字符出现的位置  
    }
    return max;
}