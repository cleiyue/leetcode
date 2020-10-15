/*
 * @lc app=leetcode id=648 lang=c
 *
 * [648] Replace Words
 */

typedef struct node {
    bool end;
    struct node* children[26];
} Node;

Node* createNode() {
    Node* node = malloc(sizeof(Node));
    for (int i = 0; i < 26; i++) node->children[i] = NULL;
    node->end = false;
    return node;
}

Node* createTrie(char** dict, int dictSize) {
    Node* trie = createNode();
    trie->end = true;
    for (int i = 0; i < dictSize; i++) {
        Node* next = trie;
        int len = strlen(dict[i]);
        for (int j = 0; j < len; j++) {
            if (next->children[dict[i][j] - 'a'] == NULL) {
                next->children[dict[i][j] - 'a'] = createNode();
            }
            if (j == len - 1) next->children[dict[i][j] - 'a']->end = true;
            next = next->children[dict[i][j] - 'a'];
        }
    }
    return trie;
}

char* replaceWords(char** dict, int dictSize, char* sentence) {
    Node* trie = createTrie(dict, dictSize);
    int slen = strlen(sentence);
    char* ans = malloc((slen + 1) * sizeof(char));
    int k = 0;
    for (int i = 0; i < slen; i++) {
        if (i == 0 || sentence[i - 1] == ' ') {
            Node* next = trie;
            int j = i;
            while (j < slen) {
                char c = sentence[j];
                if (c == ' ') {  //找到空格符，证明没有root
                    next = NULL;
                } else {
                    next = next->children[c - 'a'];
                }
                if (next == NULL) {
                    k = k - (j - i);
                    ans[k++] = sentence[i];
                    break;
                }
                ans[k++] = c;
                if (next->end == true) {
                    //下一个单词的开始
                    while (j < slen) {
                        if (j == slen - 1) {
                            i = j;
                            break;
                        }
                        if (sentence[j] == ' ') {
                            ans[k++] = ' ';
                            i = j;
                            break;
                        }
                        j++;
                    }
                    break;
                }
                j++;
            }
        } else {
            ans[k++] = sentence[i];
        }
    }
    ans[k] = '\0';
    return ans;
}
