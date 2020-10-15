/*
 * @lc app=leetcode id=11 lang=c
 *
 * [11] Container With Most Water
 */

int MIN(int a, int b) {
    return (a < b) ? a : b;
}

int maxArea(int *height, int heightSize) {
    int r = heightSize - 1;
    int max = 0;
    int l = 0;
    int temp = 0;
    while (l < r) {
        temp = (r - l) * MIN(height[l], height[r]);
        if (temp > max)
            max = temp;

        if (height[l] > height[r])
            r--;
        else
            l++;
    }
    return max;
}
