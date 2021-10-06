int maxArea(int* height, int heightSize){
    if(heightSize==2)
        return fmin(height[0],height[1]);
    int i,j,max,cur;
    max=cur=0;
    i=0;
    j=heightSize-1;
    while(i<j){
        cur=fmin(height[i],height[j])*(j-i);
        max=fmax(max,cur);
        if(height[i]<height[j])
            i++;
        else
            j--;
    }
    return max;
}