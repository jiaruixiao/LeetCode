#define MAX_LEN 100000

int cmpInt(const void* a, const void* b)
{
    return (*(int* )a - *(int* )b);
}

bool isNewArray(int** nums, int nSize, int a, int b, int c)
{
    bool isNew = true;
    for (int i = 0; i < nSize; i++) {
        if (nums[i][0] == a && 
            nums[i][1] == b && 
            nums[i][2] == c) {
            isNew = false;
            break;
        }
    }
    return isNew;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 3) {
        return NULL;
    }
    int** pOut = (int** )malloc(sizeof(int*) * MAX_LEN);
    *returnColumnSizes = (int* )malloc(sizeof(int) * MAX_LEN);
    
    qsort(nums, numsSize, sizeof(int), cmpInt);
    int r = numsSize - 1;
    int l = 0;
    if (nums[0] > 0 || nums[r] < 0) {
        return pOut;
    }
    for (int i = 0; i < numsSize; i++) {
        int l = i + 1;
        int r = numsSize - 1;
        int target = nums[i] * (-1);
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target && (isNewArray(pOut, *returnSize, nums[i], nums[l], nums[r]))) {
                pOut[*returnSize] = (int* )malloc(sizeof(int) * 3);
                pOut[*returnSize][0] = nums[i];
                pOut[*returnSize][1] = nums[l];
                pOut[*returnSize][2] = nums[r];
                (*returnColumnSizes)[(*returnSize)] = 3;
                (*returnSize)++;
                l++;
                continue;
            }
            if (sum > target) {
                r--;
            } else {
                l++;
            }
        }
    }
    return pOut;
}