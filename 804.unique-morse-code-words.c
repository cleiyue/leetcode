/*
 * @lc app=leetcode id=804 lang=c
 *
 * [804] Unique Morse Code Words
 */

int uniqueMorseRepresentations(char **words, int wordsSize) {
    char letters[26][5] = {".-", "-...", "-.-.", "-..", ".",
                           "..-.", "--.", "....", "..", ".---", "-.-",
                           ".-..", "--", "-.", "---", ".--.", "--.-",
                           ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int ans = 0;
    char arr[100][100];
    char str[100];
    for (int i = 0; i < wordsSize; i++) {
        strcpy(str, "");
        int len = strlen(words[i]);
        for (int j = 0; j < len; j++) {
            strcat(str, letters[words[i][j] - 'a']);
        }
        printf("%s\n", str);
        if (ans == 0) {
            strcpy(arr[ans++], str);
        } else {
            int temp = ans;
            bool have = false;
            for (int k = 0; k < temp; k++) {
                if (strcmp(arr[k], str) == 0) {
                    have = true;
                }
            }
            if (have == false) {
                strcpy(arr[ans++], str);
            }
        }
    }
    return ans;
}
