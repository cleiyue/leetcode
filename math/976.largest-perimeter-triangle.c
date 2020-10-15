/*
 * @lc app=leetcode id=976 lang=c
 *
 * [976] Largest Perimeter Triangle
 */

int cmp(const int* a, const int* b) {
    return (*b - *a);
}

int largestPerimeter(int* A, int ASize) {
    qsort(A, ASize, sizeof(int), cmp);
    for (int i = 0; i < ASize - 2; i++) {
        if (A[i] < A[i + 2] + A[i + 1]) {
            return (A[i + 2] + A[i + 1] + A[i]);
        }
    }
    return 0;
}
