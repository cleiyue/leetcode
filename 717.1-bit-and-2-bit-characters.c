/*
 * @lc app=leetcode id=717 lang=c
 *
 * [717] 1-bit and 2-bit Characters
 */

bool isOneBitCharacter(int *bits, int bitsSize) {
    int i = 0;
    while (true) {
        if (bits[i] == 1) {
            i += 2;
            if (i > bitsSize - 1) {
                return false;
            }
        } else {
            if (i == bitsSize - 1) {
                return true;
            }
            i++;
        }
    }
}
