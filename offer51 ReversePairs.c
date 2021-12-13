int tmp[50005];
int res=0;

long long merge_sort(int*nums,int l,int r){
    if(l>=r)
        return 0;
    int m=(l+r)/2;
    long long res=merge_sort(nums,l,m)+merge_sort(nums,m+1,r);
    for(int k = l; k <= r; k++)
        tmp[k] = nums[k];
    //对[l,r]中的[l,m]、[m+1,r]开始合并
    int i = l;
    int j = m + 1;
    for(int k = l; k <= r; k++){
        //m及其左边元素合并完毕,把右边剩下的放入合并后的数组
        if(i==m+1){
            nums[k] = tmp[j];
            j++;
        }
        //m+1及其右边元素合并完毕,把左边剩下的放入合并后的数组
        //或左边数组的元素小于等于右边,将左边数组的元素放入结果数组中,并让索引i加1
        else if(j==r+1 || tmp[i]<=tmp[j]){
            nums[k] = tmp[i];
            i++;
        }
        //右边数组的元素小于左边,将右边数组的元素其放入结果数组中,并让索引j加1
        //并且此时左边数组中的从i到m的所有数都是大于tmp[j]的(因为m左右的数组都是已经排好序的，第8行代码的功劳)
        //即此时有m-i+1个逆序对，加到res上即可
        else{    //即if(tmp[i]>tmp[j])这种情况
            nums[k] = tmp[j];
            j++;
            res += m-i+1;
        }
    }
    return res;
}

int reversePairs(int* nums, int numsSize){
    // if(numsSize==0||numsSize==1)
    //     return 0;
    // int count,i,j;
    // count=0;
    // for(i=0;i<numsSize-1;i++)
    //     for(j=i+1;j<numsSize;j++)
    //         if(nums[i]>nums[j])
    //             count++;
    // return count;

    //time out!
    if(numsSize==0||numsSize==1)
        return 0;
    return merge_sort(nums,0,numsSize-1);
}