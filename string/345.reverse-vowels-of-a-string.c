/*
 * @lc app=leetcode id=345 lang=c
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start

// "aoeiuAOEIU"

bool isVowel(char s) {
    char *vowels = "aoeiuAOEIU";
    int l = strlen(vowels);
    for (int i = 0; i < l; i++) {
        if (s == vowels[i]) return true;
    }
    return false;
}

void swap(char *l, char *r) {
    char temp = *l;
    *l = *r;
    *r = temp;
}

char *reverseVowels(char *s) {
    int len = strlen(s);
    int i = 0, j = len - 1;
    while (i < j) {
        if (!isVowel(s[i])) i++;
        if (!isVowel(s[j])) j--;
        if (isVowel(s[i]) && isVowel(s[j])) {
            swap(&s[i], &s[j]);
            i++;
            j--;
        }
    }
    return s;
}
// @lc code=end
