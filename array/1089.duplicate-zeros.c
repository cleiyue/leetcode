void duplicateZeros(int *arr, int arrSize) {
    int count = 0, index = -1;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 0) {
            if (count >= 0 && i < arrSize - count - 1) {
                count++;
                index = i;
            }
        }
    }
    int criticalIndex = (arrSize - 1) - count;
    int k = arrSize - 1;
    if (criticalIndex == index && arr[criticalIndex] == 0) {
        arr[k] = 0;
        arr[k - 1] = 0;
        k -= 2;
    } else {
        arr[k] = arr[criticalIndex];
        k--;
    }
    criticalIndex--;
    for (int i = criticalIndex; i >= 0; i--) {
        if (arr[i] == 0) {
            arr[k] = 0;
            k--;
        }
        arr[k] = arr[i];
        k--;
    }
}