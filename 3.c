int lengthOfLongestSubstring(char * s){
    int len;
    int left=0,right=1,max=0;
    len=strlen(s);
    if(len<=1)
        return len;
    int hash[256]={0};
    hash[s[left]]=1;
    while(right<len){
        hash[s[right]]++;
        while(hash[s[right]]>1){
            hash[s[left]]--;
            left++;
        }
        max=fmax(max,right-left+1);
        right++;
    }
    return max;
}