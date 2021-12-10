/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSIZE 200000
void dfs(char** res,int* returnSize,char* s,int len,int cur_len,char* hash){
    if(len==cur_len){
        res[*returnSize]=malloc(sizeof(char)*(len+1));
        strcpy(res[*returnSize],s);
        (*returnSize)++;
        return ;
    }
    char hashtmp[26]={0};
    memcpy(hashtmp,hash,26);
    if(cur_len!=0){
        hashtmp[s[cur_len-1]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(hashtmp[i]>0){
            s[cur_len]=i+'a';
            dfs(res,returnSize,s,len,cur_len+1,hashtmp);
        }
    }
    return ;
}

char** permutation(char* s, int* returnSize){
    int len=strlen(s);
    char** res=(char**)malloc(sizeof(char)*MAXSIZE);
    char hash[26]={0};
    char* tmp=NULL;
    int i;
    *returnSize=0;
    for(i=0;i<len;i++)
        hash[s[i]-'a']++;
    tmp=(char*)malloc(sizeof(char)*(len+1));
    memset(tmp,0,len+1);
    dfs(res,returnSize,tmp,len,0,hash);
    return res;
}