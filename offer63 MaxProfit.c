int maxProfit(int* prices, int pricesSize){
    // int i,j,pro,cur;
    // pro=0;
    // for(i=0;i<pricesSize-1;i++){
    //     for(j=i+1;j<pricesSize;j++){
    //         cur=prices[j]-prices[i];
    //         pro=fmax(pro,cur);
    //     }
    // }
    // return pro;
    //time is too long, need to use dp
    if(pricesSize==0)
        return 0;
    int low,pro,i;
    pro=0;
    low=prices[0];
    for(i=0;i<pricesSize;i++){
        low=fmin(low,prices[i]);
        pro=fmax(pro,prices[i]-low);
    }
    return pro;
}