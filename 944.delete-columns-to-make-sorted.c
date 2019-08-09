/*
 * @lc app=leetcode id=944 lang=c
 *
 * [944] Delete Columns to Make Sorted
 */

int minDeletionSize(char** A, int ASize) {
    int len = strlen(A[0]);
    int ans = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 1; j < ASize; j++) {
            if (A[j][i] - A[j - 1][i] < 0) {
                ans++;
                break;
            }
        }
    }
    return ans;
}
