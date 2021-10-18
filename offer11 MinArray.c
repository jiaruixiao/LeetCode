int minArray(int* numbers, int numbersSize){
    // int i;
    // for(i=0;i<numbersSize-1;i++){
    //     if(numbers[i+1]<numbers[i])
    //         return numbers[i+1];
    // }
    // return numbers[0];
    int i,j,m;
    i=0;
    j=numbersSize-1;
    while(i<j){
        m=(i+j)/2;
        if(numbers[m]>numbers[j])
            i=m+1;
        else if(numbers[m]<numbers[j])
            j=m;
        else
            j--;
    }
    return numbers[i];
}