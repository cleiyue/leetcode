/*
 * @lc app=leetcode id=1046 lang=c
 *
 * [1046] Last Stone Weight
 */

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int lastStoneWeight(int* stones, int stonesSize) {
    for (int i = stonesSize - 1; i >= 1; i--) {
        qsort(stones, stonesSize, sizeof(int), cmp);
        if (stones[stonesSize - 1] && stones[stonesSize - 2]) {
            stones[stonesSize - 1] = abs(stones[stonesSize - 1] - stones[stonesSize - 2]);
            stones[stonesSize - 2] = 0;
        } else {
            return stones[stonesSize - 1];
        }
    }
    return stones[stonesSize - 1];
}
