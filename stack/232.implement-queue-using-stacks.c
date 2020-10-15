/*
 * @lc app=leetcode id=232 lang=c
 *
 * [232] Implement Queue using Stacks
 */

typedef struct {
    int idx;
    int* arr;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* queue = malloc(sizeof(MyQueue));
    queue->idx = 0;
    queue->arr = calloc(100, sizeof(int));
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    for (int i = obj->idx; i >= 1; i--) {
        obj->arr[i] = obj->arr[i - 1];
    }
    obj->arr[0] = x;
    obj->idx = obj->idx + 1;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    obj->idx--;
    return obj->arr[obj->idx];
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->arr[obj->idx - 1];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->idx == 0;
}

void myQueueFree(MyQueue* obj) {
    obj->idx = 0;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
