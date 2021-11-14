int getdigit(int x){
    int sum=1;
    while((x/=10)!=0)
        sum++;
    return sum;
}

int comp(const void  *a, const void *b){
	int num1=*(int*)a, num2=*(int*)b;
	unsigned long long sum1=num1*pow(10, getdigit(num2))+num2;
    unsigned long long sum2=num2*pow(10, getdigit(num1))+num1;
	return sum1-sum2;
}

char* minNumber(int* nums, int numsSize){
    int sum=0, digit=0;
    qsort(nums, numsSize, sizeof(int), comp);
    for(int i=0;i<numsSize;i++)
		sum+=getdigit(nums[i]);
	char *str=(char*)malloc((sum+1)*sizeof(char));
	for(int i=0;i<numsSize;i++){
		sprintf(str+digit, "%d", nums[i]);
		digit+=getdigit(nums[i]);
	}
    return str;
}