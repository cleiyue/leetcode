/*
 * @lc app=leetcode id=225 lang=c
 *
 * [225] Implement Stack using Queues
 */

typedef struct {
    int idx;
    int* arr;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* stack = malloc(sizeof(MyStack));
    stack->idx = 0;
    stack->arr = calloc(100, sizeof(int));
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->arr[obj->idx++] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    obj->idx--;
    return obj->arr[obj->idx];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->arr[obj->idx - 1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->idx == 0;
}

void myStackFree(MyStack* obj) {
    obj->idx = 0;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
