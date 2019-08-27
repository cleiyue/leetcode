/*
 * @lc app=leetcode id=720 lang=c
 *
 * [720] Longest Word in Dictionary
 */

typedef struct node {
    bool end;
    struct node *children[26];
} Node;

int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

char *longestWord(char **words, int wordsSize) {
    qsort(words, wordsSize, sizeof(words[0]), cmp);
    Node *trie = malloc(sizeof(Node));
    for (int i = 0; i < 26; i++) trie->children[i] = NULL;
    int max = 0, index = 0;
    for (int i = 0; i < wordsSize; i++) {
        Node *next = trie;
        int temp = 0, len = strlen(words[i]);
        for (int j = 0; j < len; j++) {
            Node *n;
            if (next->children[words[i][j] - 'a'] == NULL) {
                n = malloc(sizeof(Node));
                for (int i = 0; i < 26; i++) n->children[i] = NULL;
                n->end = false;
            } else {
                n = next->children[words[i][j] - 'a'];
            }
            if (j == len - 1) n->end = true;
            if (n->end == false) break;
            next = next->children[words[i][j] - 'a'] = n;
            if (next->end == true) temp++;
            if (j == len - 1 && temp > max) {
                max = temp;
                index = i;
            }
        }
    }
    return words[index];
}
