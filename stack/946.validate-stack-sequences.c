/*
 * @lc app=leetcode id=946 lang=c
 *
 * [946] Validate Stack Sequences
 */

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int idx = 0;
    int* arr = malloc(pushedSize * sizeof(int));
    int pop_idx = 0;
    for (int i = 0; i < pushedSize; i++) {
        arr[idx++] = pushed[i];
        if (popped[pop_idx] == arr[idx - 1]) {
            for (int j = pop_idx; j < poppedSize; j++) {
                if (idx > 0 && popped[j] == arr[idx - 1]) {
                    idx--;
                    pop_idx++;
                } else {
                    break;
                }
            }
        }
    }
    return idx == 0;
}
