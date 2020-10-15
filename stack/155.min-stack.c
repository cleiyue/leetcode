/*
 * @lc app=leetcode id=155 lang=c
 *
 * [155] Min Stack
 */

typedef struct {
    int idx;
    int min;
    int* arr;
} MinStack;

/** initialize your data structure here. */
#define MAX 2147483647
#define ARR_SIZE 10000
MinStack* minStackCreate() {
    MinStack* stack = malloc(sizeof(MinStack));
    stack->idx = 0;
    stack->min = MAX;
    stack->arr = calloc(ARR_SIZE, sizeof(int));
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    if (x < obj->min) {
        obj->min = x;
    }
    obj->arr[obj->idx++] = x;
}

void minStackPop(MinStack* obj) {
    obj->idx--;
    obj->min = MAX;
    for (int i = 0; i < obj->idx; i++) {
        if (obj->arr[i] < obj->min) {
            obj->min = obj->arr[i];
        }
    }
    return obj->arr[obj->idx];
}

int minStackTop(MinStack* obj) {
    return obj->arr[obj->idx - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    obj->idx = 0;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
