/*
 * @lc app=leetcode id=463 lang=c
 *
 * [463] Island Perimeter
 */

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int ans = 0;
    for (int i = 0; i < gridSize; i++) {
        int* row = grid[i];
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                //left
                if (j == 0 || grid[i][j - 1] == 0) {
                    ans++;
                }
                //top
                if (i == 0 || grid[i - 1][j] == 0) {
                    ans++;
                }
                //right
                if (j == *gridColSize - 1 || grid[i][j + 1] == 0) {
                    ans++;
                }
                //bottom
                if (i == gridSize - 1 || grid[i + 1][j] == 0) {
                    ans++;
                }
            }
        }
    }
    return ans;
}
