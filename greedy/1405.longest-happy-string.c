/*
 * @lc app=leetcode id=1405 lang=c
 *
 * [1405] Longest Happy String
 */

// @lc code=start

struct Node {
    int num;
    char letter;
};

int cmp(const void* a, const void* b) {
    struct Node ap = *(struct Node*)a;
    struct Node bp = *(struct Node*)b;
    return bp.num - ap.num;
}

char* longestDiverseString(int a, int b, int c) {
    struct Node list[3] = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
    char* ans = malloc(sizeof(char) * (a + b + c + 1));
    // 每次进行排序，先放最多的，如果重复则放次多的
    int idx = 0;
    while (true) {
        qsort(list, 3, sizeof(list[0]), cmp);
        if (idx >= 2 && ans[idx - 1] == list[0].letter && ans[idx - 2] == list[0].letter) {
            if ((&list[1])->num-- > 0) {
                ans[idx++] = list[1].letter;
            } else {
                break;
            }
        } else {
            if ((&list[0])->num-- > 0) {
                ans[idx++] = list[0].letter;
            } else {
                break;
            }
        }
    }
    ans[idx++] = '\0';
    return ans;
}
// @lc code=end
