#define ABS(n) (n < 0 ? -n : n)
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
int dvd(unsigned int a, unsigned int b){
    int tmp = 0;
    while (a > b){
        tmp++;
        b <<= 1;
    }
    return a == b ? tmp : tmp - 1;
}

int divide(int a, int b){
    if (a == 0) 
        return 0;
    if (a == INT_MIN && b == -1)
        return INT_MAX;
    else if (a == INT_MIN && b == 1) 
        return INT_MIN;
    bool isNeg = (a ^ b) < 0;
    unsigned int al = a == INT_MIN ? (unsigned int)a : ABS(a), bl = b == INT_MIN ? (unsigned int)b : ABS(b);
    int res = 0, tmp = 0;
    while (al >= bl){
        tmp = dvd(al, bl);
        res += 1<<tmp;
        al -= bl<<tmp;
    }
    res = isNeg ? -res : res;
    return res;
}