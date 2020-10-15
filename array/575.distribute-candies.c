/*
 * @lc app=leetcode id=575 lang=c
 *
 * [575] Distribute Candies
 */

int distributeCandies(int* candies, int candiesSize) {
    int* ans = calloc(200001, sizeof(int));
    int cnt = 0;
    for (int i = 0; i < candiesSize; i++) {
        ans[candies[i] + 100000]++;
        if (ans[candies[i] + 100000] == 1) {
            cnt++;
        }
    }
    if (cnt > candiesSize / 2) {
        return candiesSize / 2;
    } else {
        return cnt;
    }
}
