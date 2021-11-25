bool verifyPostorder(int* postorder, int postorderSize){
    if(postorderSize==0||postorder==NULL)
        return true;
    int left_len=0;
    while(postorder[left_len]<postorder[postorderSize-1])
        left_len++;
    int i;
    for(i=left_len;i<postorderSize-1;i++)
        if(postorder[i]<postorder[postorderSize-1])
            return false;
    return verifyPostorder(postorder,left_len)&&verifyPostorder(postorder+left_len,postorderSize-left_len-1);
}