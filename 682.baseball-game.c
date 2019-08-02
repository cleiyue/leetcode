/*
 * @lc app=leetcode id=682 lang=c
 *
 * [682] Baseball Game
 */

int calPoints(char **ops, int opsSize) {
    int index = 0;
    int *arr = calloc(opsSize, sizeof(int));
    for (int i = 0; i < opsSize; i++) {
        if (index > 0 && ops[i][0] == 'C') {
            index--;
        } else if (ops[i][0] == '+') {
            arr[index++] = arr[index - 1] + arr[index - 2];
        } else if (ops[i][0] == 'D') {
            arr[index++] = arr[index - 1] * 2;
        } else {
            arr[index++] = atoi(ops[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < index; i++) {
        ans += arr[i];
    }
    return ans;
}
