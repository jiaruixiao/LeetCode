#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char * longestPalindrome(char * s){
    int len,i;
    len=strlen(s);
    if(len<=1)
        return s;
    int start,end;
    int len1,len2,max_len;
    start=end=0;
    for(i=0;i<len;i++){
        len1=expandAroundCenter(s,i,i);     //字数为奇数
        // printf("%d\n",len1);
        len2=expandAroundCenter(s,i,i+1);   //字数为偶数
        // printf("%d\n",len2);
        max_len=fmax(len1,len2);
        if(max_len>end-start){
            start=i-(max_len-1)/2;
            end=i+max_len/2;
        }
    }
    // printf("%d\n",end-start+1);
    char *p;
    p=(char*) malloc((end-start+2 )* sizeof(char));
    // char *q=p;
    for(i=0;i<end-start+1&&i<len;i++)
        p[i]=s[i+start];
    p[end-start+1]='\0';
    return p;
}


int expandAroundCenter(char * s, int left, int right){
    int L = left, R = right;
    int len=strlen(s);
    while (L >= 0 && R < len && s[L] == s[R]){
        L--;
        R++;
    }
    return R - L - 1;
}