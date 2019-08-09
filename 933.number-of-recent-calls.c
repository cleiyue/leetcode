/*
 * @lc app=leetcode id=933 lang=c
 *
 * [933] Number of Recent Calls
 */

typedef struct {
    int* arr;
    int idx;
    int start;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = malloc(sizeof(RecentCounter));
    obj->arr = malloc(10000 * sizeof(int));
    obj->idx = 0;
    obj->start = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->arr[obj->idx++] = t;
    for (int i = obj->start; i < obj->idx; i++) {
        if (t - 3000 <= obj->arr[i] && obj->arr[i] <= t) {
            obj->start = i;
            return obj->idx - i;
        }
    }
    return -1;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/
