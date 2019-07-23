//[1,1,4,2,1,3]    ->[1,1,1,2,3,4]
//


int compare(int *a, int *b) {
    if (*a > *b)
        return 1;
    if (*a == *b)
        return 0;
    return -1;
}

int heightChecker(int *heights, int heightsSize) {
    int *arr = malloc(heightsSize * sizeof(int));
    for (int i = 0; i < heightsSize; i++) {
        arr[i] = heights[i];
    }
    qsort(arr, heightsSize, sizeof(int), compare);
    int count = 0;

    for (int i = 0; i < heightsSize; i++) {
        if (arr[i] != heights[i]) {
            count++;
        }
    }
    return count;
}
