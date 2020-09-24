/*
 * @lc app=leetcode id=13 lang=c
 *
 * [13] Roman to Integer
 */

int romanToInt(char* s) {
    int count = 0;
    while (*s) {
        if (*s == 'V')
            count += 5;
        else if (*s == 'L')
            count += 50;
        else if (*s == 'D')
            count += 500;
        else if (*s == 'M')
            count += 1000;
        else if (*s == 'I')
            ((*(s + 1) == 'V') || (*(s + 1) == 'X')) ? (count -= 1) : (count += 1);
        else if (*s == 'X')
            ((*(s + 1) == 'L') || (*(s + 1) == 'C')) ? (count -= 10) : (count += 10);
        else
            ((*(s + 1) == 'D') || (*(s + 1) == 'M')) ? (count -= 100) : (count += 100);

        s++;
    }

    return count;
}
