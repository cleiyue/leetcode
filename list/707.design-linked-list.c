/*
 * @lc app=leetcode id=707 lang=c
 *
 * [707] Design Linked List
 */

typedef struct node {
    int val;
    struct node* next;
} MyLinkedList;

/** Initialize your data structure here. */
#define DEFAULT -1000

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->val = DEFAULT;
    obj->next = NULL;
    return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0) return -1;
    for (int i = 0; i < index; i++) {
        if (obj != NULL) {
            obj = obj->next;
        } else {
            return -1;
        }
    }
    if (obj != NULL && obj->val != DEFAULT) return obj->val;
    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    printf("myLinkedListAddAtHead addAtHead %d\n", obj->val);
    if (obj->val == DEFAULT) {
        printf("NULL addAtHead %d\n", val);
        obj->val = val;
    } else {
        printf("NOt NULL addAtHead %d\n", val);
        MyLinkedList* temp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
        temp->val = obj->val;
        temp->next = obj->next;
        obj->val = val;
        obj->next = temp;
    }
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* temp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    temp->val = val;
    temp->next = NULL;
    while (obj->next != NULL) {
        obj = obj->next;
    }
    obj->next = temp;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index <= 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    //需要先初始化头结点
    if (index >= 1 && obj->val == DEFAULT) return;
    //找到 index 前一个结点
    for (int i = 0; i < index - 1; i++) {
        if (obj == NULL) return;
        obj = obj->next;
    }
    //如果前一个结点是空，则跳过
    if (obj == NULL) return;
    MyLinkedList* temp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    temp->val = val;
    temp->next = obj->next;
    obj->next = temp;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0) return;
    if (index == 0 && obj->next == NULL) {
        obj->val = DEFAULT;
        return;
    }
    if (index == 0 && obj->next != NULL) {
        obj->val = obj->next->val;
        obj->next = obj->next->next;
        return;
    }
    //找到需要删除的前一个结点
    for (int i = 0; i < index - 1; i++) {
        if (obj == NULL) return;
        obj = obj->next;
    }
    if (obj != NULL && obj->next != NULL) {
        obj->next = obj->next->next;
    } else if (obj != NULL && obj->next == NULL) {
        obj->next = NULL;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
