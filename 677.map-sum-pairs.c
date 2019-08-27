/*
 * @lc app=leetcode id=677 lang=c
 *
 * [677] Map Sum Pairs
 */

typedef struct node {
    int sum;
    bool end;
    struct node* children[26];
} MapSum;

/** Initialize your data structure here. */
MapSum* createNode() {
    MapSum* obj = malloc(sizeof(MapSum));
    for (int i = 0; i < 26; i++) obj->children[i] = NULL;
    obj->sum = 0;
    obj->end = false;
    return obj;
}

MapSum* mapSumCreate() {
    return createNode();
}

void mapSumInsert(MapSum* obj, char* key, int val) {
    int len = strlen(key);
    MapSum* next = obj;
    for (int i = 0; i < len; i++) {
        MapSum* temp = next->children[key[i] - 'a'];
        if (temp == NULL) {
            temp = createNode();
        }
        //产生了重复key
        if (i == len - 1 && temp->end == true) {
            int old = temp->sum;
            temp->sum = val;
            MapSum* _next = obj;
            for (int j = 0; j < len - 1; j++) {
                _next->children[key[j] - 'a']->sum -= old;
                _next = _next->children[key[j] - 'a'];
            }
        } else {
            temp->sum += val;
        }
        if (i == len - 1) {
            temp->end = true;
        }
        next = next->children[key[i] - 'a'] = temp;
    }
}

int mapSumSum(MapSum* obj, char* prefix) {
    int len = strlen(prefix);
    int min = INT_MAX;
    MapSum* next = obj;
    for (int i = 0; i < len; i++) {
        MapSum* temp = next->children[prefix[i] - 'a'];
        if (temp == NULL) {
            return 0;
        }
        if (min > temp->sum) {
            min = temp->sum;
        }
        next = temp;
    }
    return min;
}

void mapSumFree(MapSum* obj) {
    free(obj);
}

/**
 * Your MapSum struct will be instantiated and called as such:
 * MapSum* obj = mapSumCreate();
 * mapSumInsert(obj, key, val);
 
 * int param_2 = mapSumSum(obj, prefix);
 
 * mapSumFree(obj);
*/
