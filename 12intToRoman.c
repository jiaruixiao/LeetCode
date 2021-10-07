char * intToRoman(int num){
    char *p;
    p=(char *)malloc(sizeof(char)*20);
    int thousand=num/1000;
    int i=0;
    if(thousand==1){
        p[i]='M';
        i++;
    }
    else if(thousand==2){
        p[i]='M';
        p[i+1]='M';
        i=i+2;
    }
    else if(thousand==3){
        p[i]='M';
        p[i+1]='M';
        p[i+2]='M';
        i=i+3;
    }
    int hundred=(num-thousand*1000)/100;
    if(hundred==9){
        p[i]='C';
        p[i+1]='M';
        i=i+2;
    }
    else if(hundred==8){
        p[i]='D';
        p[i+1]='C';
        p[i+2]='C';
        p[i+3]='C';
        i=i+4;
    }
    else if(hundred==7){
        p[i]='D';
        p[i+1]='C';
        p[i+2]='C';
        i=i+3;
    }
    else if(hundred==6){
        p[i]='D';
        p[i+1]='C';
        i=i+2;
    }
    else if(hundred==5){
        p[i]='D';
        i=i+1;
    }
    else if(hundred==4){
        p[i]='C';
        p[i+1]='D';
        i=i+2;
    }
    else if(hundred==3){
        p[i]='C';
        p[i+1]='C';
        p[i+2]='C';
        i=i+3;
    }
    else if(hundred==2){
        p[i]='C';
        p[i+1]='C';
        i=i+2;
    }
    else if(hundred==1){
        p[i]='C';
        i=i+1;
    }

    int ten=(num-thousand*1000-hundred*100)/10;
    if(ten==9){
        p[i]='X';
        p[i+1]='C';
        i=i+2;
    }
    else if(ten==8){
        p[i]='L';
        p[i+1]='X';
        p[i+2]='X';
        p[i+3]='X';
        i=i+4;
    }
    else if(ten==7){
        p[i]='L';
        p[i+1]='X';
        p[i+2]='X';
        i=i+3;
    }
    else if(ten==6){
        p[i]='L';
        p[i+1]='X';
        i=i+2;
    }
    else if(ten==5){
        p[i]='L';
        i=i+1;
    }
    else if(ten==4){
        p[i]='X';
        p[i+1]='L';
        i=i+2;
    }
    else if(ten==3){
        p[i]='X';
        p[i+1]='X';
        p[i+2]='X';
        i=i+3;
    }
    else if(ten==2){
        p[i]='X';
        p[i+1]='X';
        i=i+2;
    }
    else if(ten==1){
        p[i]='X';
        i=i+1;
    }

    int one=(num-thousand*1000-hundred*100-ten*10);
    if(one==9){
        p[i]='I';
        p[i+1]='X';
        i=i+2;
    }
    else if(one==8){
        p[i]='V';
        p[i+1]='I';
        p[i+2]='I';
        p[i+3]='I';
        i=i+4;
    }
    else if(one==7){
        p[i]='V';
        p[i+1]='I';
        p[i+2]='I';
        i=i+3;
    }
    else if(one==6){
        p[i]='V';
        p[i+1]='I';
        i=i+2;
    }
    else if(one==5){
        p[i]='V';
        i=i+1;
    }
    else if(one==4){
        p[i]='I';
        p[i+1]='V';
        i=i+2;
    }
    else if(one==3){
        p[i]='I';
        p[i+1]='I';
        p[i+2]='I';
        i=i+3;
    }
    else if(one==2){
        p[i]='I';
        p[i+1]='I';
        i=i+2;
    }
    else if(one==1){
        p[i]='I';
        i=i+1;
    }

    p[i]='\0';
    return p;
}