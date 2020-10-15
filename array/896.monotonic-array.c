/*
 * @lc app=leetcode id=896 lang=c
 *
 * [896] Monotonic Array
 */

bool isMonotonic(int *A, int ASize) {
    if (ASize < 3) {
        return true;
    }
    int increasing = 0;
    int k = A[0];
    for (int i = 1; i < ASize; i++) {
        if (A[i] == k) {
            k = A[i];
        } else if (A[i] > k) {
            k = A[i];
            if (increasing == 0) {
                increasing = 1;
            }

            if (increasing == 2) {
                return false;
            }
        } else {
            k = A[i];
            if (increasing == 0) {
                increasing = 2;
            }
            if (increasing == 1) {
                return false;
            }
        }
    }
    return true;
}
