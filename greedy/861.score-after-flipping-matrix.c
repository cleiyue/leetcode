/*
 * @lc app=leetcode id=861 lang=c
 *
 * [861] Score After Flipping Matrix
 */

// @lc code=start

// 第一列都为1，之后的列取最多的1
#define MAX(a, b) (a > b ? a : b)  //不加括号导致下面ans计算错误
int matrixScore(int** A, int ASize, int* AColSize) {
    int ans = 0;
    for (int i = 0; i < *AColSize; i++) {
        int col = 0;
        for (int j = 0; j < ASize; j++) {
            col += A[j][i] ^ A[j][0];  //重要函数
        }
        ans += MAX(col, ASize - col) * (1 << (*AColSize - 1 - i));
    }
    return ans;
}
// @lc code=end
