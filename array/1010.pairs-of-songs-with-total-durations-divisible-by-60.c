/*
 * @lc app=leetcode id=1010 lang=c
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */

int numPairsDivisibleBy60(int* time, int timeSize) {
    int* arr = calloc(60, sizeof(int));  //速度快int arr[60] = {0};
    int ans = 0;
    for (int i = 0; i < timeSize; i++) {
        int t = time[i] % 60;
        int y = (60 - t) % 60;
        ans += arr[y];
        arr[t]++;
    }
    return ans;
}
