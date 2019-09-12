/*
 * @lc app=leetcode id=731 lang=c
 *
 * [731] My Calendar II
 */

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)

typedef struct Calendar {
    int** calendar;
    int cdx;
    int** overlaps;
    int odx;
} MyCalendarTwo;

MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj = malloc(sizeof(MyCalendarTwo));
    obj->calendar = malloc(1000 * sizeof(int*));
    obj->cdx = 0;
    obj->overlaps = malloc(1000 * sizeof(int*));
    obj->odx = 0;
    return obj;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    for (int i = 0; i < obj->odx; i++) {
        if ((obj->overlaps)[i][0] < end && start < (obj->overlaps)[i][1]) return false;
    }
    for (int i = 0; i < obj->cdx; i++) {
        if (obj->calendar[i][0] < end && start < obj->calendar[i][1]) {
            int* row = malloc(2 * sizeof(int));
            row[0] = MAX(start, obj->calendar[i][0]);
            row[1] = MIN(end, obj->calendar[i][1]);
            obj->overlaps[obj->odx++] = row;
        }
    }
    int* row = malloc(2 * sizeof(int));
    row[0] = start;
    row[1] = end;
    obj->calendar[obj->cdx++] = row;
    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj);
}

/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);
 
 * myCalendarTwoFree(obj);
*/
