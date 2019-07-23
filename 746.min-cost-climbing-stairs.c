/*
 * @lc app=leetcode id=746 lang=c
 *
 * [746] Min Cost Climbing Stairs
 */

#define MIN(a, b) (a > b ? b : a)
int minCostClimbingStairs(int* cost, int costSize) {
    int f1 = 0, f2 = 0;
    for (int i = costSize - 1; i >= 0; --i) {
        int f0 = cost[i] + MIN(f1, f2);
        f2 = f1;
        f1 = f0;
    }
    return MIN(f1, f2);
}
