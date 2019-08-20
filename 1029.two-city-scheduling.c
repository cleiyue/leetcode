/*
 * @lc app=leetcode id=1029 lang=c
 *
 * [1029] Two City Scheduling
 */

int cmp(const void* a, const void* b) {
    int** c = (int**)a;
    int** d = (int**)b;
    int dis = (c[0][0] - c[0][1]) - (d[0][0] - d[0][1]);
    return dis;
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize) {
    int ans = 0;
    qsort(costs, costsSize, sizeof(costs[0]), cmp);
    for (int i = 0; i < costsSize; i++) {
        if (i < costsSize / 2) {
            ans += costs[i][0];
        } else {
            ans += costs[i][1];
        }
    }
    return ans;
}
