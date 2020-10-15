/*
 * @lc app=leetcode id=961 lang=c
 *
 * [961] N-Repeated Element in Size 2N Array
 */

int repeatedNTimes(int* A, int ASize) {
    int* hash = calloc(10000, sizeof(int));
    for (int i = 0; i < ASize; i++) {
        hash[A[i]]++;
        if (hash[A[i]] > 1) {
            return A[i];
        }
    }
    return 0;
}
