/*
 * @lc app=leetcode id=1002 lang=c
 *
 * [1002] Find Common Characters
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int count(char *str, int length, char c) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

int exist(char **A, int ASize, char c, int times) {
    for (int i = 1; i < ASize; i++) {
        char *s = A[i];
        int len = strlen(s);
        int _times = count(s, len, c);  //返回出现次数
        if (_times >= times) {
            //return 0;
        } else {
            return -1;
        }
        // if (index > 0)
        // {
        //     //字符串常量无法对值进行修改
        //     //s[index] = 0;
        //     //strncpy(s,s+1,len-1);
        // }
        // else
        // {
        //     return -1;
        // }
    }
    return 0;
}

int times(char **B, int size, char c) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strchr(B[i], c) != NULL) {
            count++;
        }
    }
    return count;
}

char **commonChars(char **A, int ASize, int *returnSize) {
    int sum = strlen(A[0]);
    char **B = malloc(sum * sizeof(char *));
    char *str = A[0];
    int length = strlen(str);  //sizeof(str) / sizeof(char);
    int count = 0;
    for (int j = 0; j < length; j++) {
        char c = str[j];
        int time = times(B, count, c);
        if (exist(A, ASize, c, time + 1) == 0) {
            B[count] = malloc(2 * sizeof(char));
            B[count][0] = c;
            B[count][1] = '\0';
            count++;
        }
    }
    *returnSize = count;
    return B;
}
