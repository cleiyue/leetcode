/*
 * @lc app=leetcode id=70 lang=c
 *
 * [70] Climbing Stairs
 */

int climbStairs(int n) {
    if (n == 1) return 1;
    int* dp = malloc((n + 1) * sizeof(int));
    dp[1] = 1;
    dp[2] = 2;
    int ans = 0;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
