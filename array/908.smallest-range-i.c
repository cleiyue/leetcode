/*
 * @lc app=leetcode id=908 lang=c
 *
 * [908] Smallest Range I
 */

int smallestRangeI(int* A, int ASize, int K) {
    if (ASize == 1) return 0;
    int low = A[0];
    int high = A[0];
    for (int i = 0; i < ASize; i++) {
        if (A[i] < low) {
            low = A[i];
        }
        if (A[i] > high) {
            high = A[i];
        }
    }
    int ans = high - low - 2 * K;
    if (ans > 0) {
        return ans;
    } else {
        return 0;
    }
}
