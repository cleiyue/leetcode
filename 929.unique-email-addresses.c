/*
 * @lc app=leetcode id=929 lang=c
 *
 * [929] Unique Email Addresses
 */

int numUniqueEmails(char **emails, int emailsSize) {
    int ans = 0;
    char arr[100][100];
    char str[100];
    int str_idx = 0;
    for (int i = 0; i < emailsSize; i++) {
        str_idx = 0;
        int len = strlen(emails[i]);
        int at_idx = 0;
        for (int j = 0; j < len; j++) {
            if (emails[i][j] == '@') {
                at_idx = j;
                str[str_idx++] = emails[i][j];
            } else if (emails[i][j] == '.' && (at_idx == 0 || j < at_idx)) {
                continue;
            } else if (emails[i][j] == '+') {
                int k = j;
                while (emails[i][k] != '@') {
                    k++;
                }
                j = k - 1;
            } else {
                str[str_idx++] = emails[i][j];
            }
        }
        str[str_idx] = '\0';
        if (ans == 0) {
            strcpy(arr[ans++], str);
        } else {
            int have = 1;
            for (int k = 0; k < ans; k++) {
                if (strcmp(arr[k], str) == 0) {
                    have = 0;
                }
            }
            if (have == 1) {
                strcpy(arr[ans++], str);
            }
        }
    }
    return ans;
}
