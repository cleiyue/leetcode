/*
 * @lc app=leetcode id=1094 lang=c
 *
 * [1094] Car Pooling
 */

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    int* arr = calloc(1001, sizeof(int));
    for (int i = 0; i < tripsSize; i++) {
        int num_passengers = trips[i][0];
        int start_location = trips[i][1];
        int end_location = trips[i][2];
        for (int j = start_location; j < end_location; j++) {
            arr[j] += num_passengers;
            if (arr[j] > capacity) {
                return false;
            }
        }
    }
    return true;
}
