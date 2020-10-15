/*
 * @lc app=leetcode id=766 lang=c
 *
 * [766] Toeplitz Matrix
 */

//3*4
//  matrix[2][0],
//  matrix[2][1], matrix[1][0],
//  matrix[2][2], matrix[1][1] ,matrix[0][0]
//  matrix[2][3], matrix[1][2] ,matrix[0][1]
//  matrix[1][3] ,matrix[0][2]
//  matrix[0][3]

//2*2
//  matrix[1][0],
//  matrix[1][1],matrix[0][0]
//  matrix[0][1]

bool isToeplitzMatrix(int **matrix, int matrixSize, int *matrixColSize) {
    for (int i = matrixSize - 1; i > 0; i--) {
        for (int j = 1; j < *matrixColSize; j++) {
            int _j = j;
            int _i = i;
            int value = matrix[i][j];
            while (_j >= 0 && _i >= 0) {
                if (matrix[_i][_j] != value) {
                    return false;
                }
                _j--;
                _i--;
            }
        }
    }
    return true;
}
