/*
 * @lc app=leetcode id=830 lang=c
 *
 * [830] Positions of Large Groups
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **largeGroupPositions(char *S, int *returnSize, int **returnColumnSizes) {
    int len = strlen(S);  //重点，不能用 sizeof 计算
    int **ans = malloc(len * sizeof(int *));
    int start = -1;
    int cnt;
    char k;
    int returnSizeCnt = 0;
    for (int i = 0; i < len; i++) {
        if (start == -1) {
            start = i;
            k = S[i];
            cnt = 1;
            continue;
        }
        if (S[i] == k) {
            cnt++;
            if (i == len - 1) {
                if (cnt >= 3) {
                    int *row = malloc(2 * sizeof(int));
                    row[0] = start;
                    row[1] = start + cnt - 1;
                    ans[returnSizeCnt] = row;
                    returnSizeCnt++;
                }
            }
        } else {
            if (cnt >= 3) {
                int *row = malloc(2 * sizeof(int));
                row[0] = start;
                row[1] = start + cnt - 1;
                ans[returnSizeCnt] = row;
                returnSizeCnt++;
            }
            //重置
            start = i;
            cnt = 1;
            k = S[i];
        }
    }

    *returnColumnSizes = malloc(returnSizeCnt * sizeof(int));
    for (int i = 0; i < returnSizeCnt; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = returnSizeCnt;
    return ans;
}
