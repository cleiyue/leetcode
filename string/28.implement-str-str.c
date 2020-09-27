/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 */


int strStr(char* haystack, char* needle) {
    int nLen = strlen(needle);
    if (nLen == 0) return 0;
    int hLen = strlen(haystack);
    for (int i = 0; i < hLen; i++) {
        for (int j = 0; j < nLen; j++) {
            if (*(haystack + i + j) == *(needle + j)) {
                if (j == nLen - 1)
                    return i;
                continue;
            } else {
                break;
            }
        }
    }
    return -1;
}

int strStr(char* haystack, char* needle) {
    int q = strlen(haystack), w = strlen(needle);
    if (w == 0) return 0;
    int i, j = 0;
    while (i < q) {
        if (haystack[i] == needle[j]) {
            if (j == w - 1) return i - j;
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    return -1;
}
