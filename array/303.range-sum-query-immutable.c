/*
 * @lc app=leetcode id=303 lang=c
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start

typedef struct {
    int* array;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* numArray;
    numArray = malloc(sizeof(NumArray));
    numArray->array = malloc(sizeof(int) * (numsSize + 1));
    numArray->array[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        numArray->array[i + 1] = numArray->array[i] + nums[i];
    }
    return numArray;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    return obj->array[j + 1] - obj->array[i];
}

void numArrayFree(NumArray* obj) {
    free(obj->array);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
// @lc code=end
