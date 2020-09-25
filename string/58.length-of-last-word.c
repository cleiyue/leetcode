/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

// @lc code=start

int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int i = 0;
    while (len-- > 0) {
        if (*(s + len) != ' ') {
            i++;
        }

        if (i > 0 && *(s + len) == ' ')
            return i;
    }
    return i;
}
// @lc code=end
