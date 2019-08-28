/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 */

struct Node {
    int cnt;
    struct Node* child[26];
};

struct Node* createNode() {
    struct Node* node = malloc(sizeof(struct Node));
    for (int i = 0; i < 26; i++) node->child[i] = NULL;
    node->cnt = 0;
    return node;
}

struct Node* createTrie(char** strs, int strsSize, char* ans) {
    int k = 0;
    struct Node* trie = createNode();
    for (int i = 0; i < strsSize; i++) {
        struct Node* next = trie;
        int len = strlen(strs[i]);
        for (int j = 0; j < len; j++) {
            struct Node* temp = next->child[strs[i][j] - 'a'];
            if (temp == NULL) {
                temp = next->child[strs[i][j] - 'a'] = createNode();
            }
            temp->cnt++;
            if (temp->cnt == strsSize) {
                ans[k++] = strs[i][j];
            }
            next = temp;
        }
    }
    ans[k] = '\0';
    return trie;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    char* ans = malloc((strlen(strs[0]) + 1) * sizeof(char));
    struct Node* trie = createTrie(strs, strsSize, ans);
    return ans;
}
