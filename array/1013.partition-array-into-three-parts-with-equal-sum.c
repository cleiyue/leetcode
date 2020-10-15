/*
 * @lc app=leetcode id=1013 lang=c
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */

int sum(int *arr, int size) {
    int sum = 0;
    while (size > 0) {
        sum += arr[size - 1];
        size--;
    }
    return sum;
}

bool canThreePartsEqualSum(int *A, int ASize) {
    int total = sum(A, ASize);
    if (total % 3 != 0) {
        return false;
    }
    int part = total / 3;
    int k = 0;
    int p = 0;
    for (int i = 0; i < ASize; i++) {
        k += A[i];
        if (k == part) {
            if (p < 2) {
                k = 0;
                p++;
            }
        }
    }
    if (k == part) {
        return true;
    } else {
        return false;
    }
}
