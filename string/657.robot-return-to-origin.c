/*
 * @lc app=leetcode id=657 lang=c
 *
 * [657] Robot Return to Origin
 */

bool judgeCircle(char* moves) {
    int l = 0;
    int u = 0;
    int len = strlen(moves);
    for (int i = 0; i < len; i++) {
        if (moves[i] == 'R') {
            l--;
        } else if (moves[i] == 'L') {
            l++;
        } else if (moves[i] == 'U') {
            u++;
        } else {
            u--;
        }
    }
    if (l == 0 && u == 0) {
        return true;
    } else {
        return false;
    }
}
