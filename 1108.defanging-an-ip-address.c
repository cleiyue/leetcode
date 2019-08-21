/*
 * @lc app=leetcode id=1108 lang=c
 *
 * [1108] Defanging an IP Address
 */

char* defangIPaddr(char* address) {
    int len = strlen(address);
    char* ans = malloc((len + 7) * sizeof(char));
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (address[i] == '.') {
            ans[k++] = '[';
            ans[k++] = '.';
            ans[k++] = ']';
        } else {
            ans[k++] = address[i];
        }
    }
    ans[k] = '\0';
    return ans;
}