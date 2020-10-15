/*
 * @lc app=leetcode id=1104 lang=c
 *
 * [1104] Path In Zigzag Labelled Binary Tree
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void findPath(int *ans, int label, int level, int *returnSize) {
    if(level < 0) return;
    int temp = label/2;
    int nextLabel = pow(2, level) + pow(2, level-1) -1 - temp;
    findPath(ans, nextLabel, level-1, returnSize);
    ans[(*returnSize)++] = label;
}

int* pathInZigZagTree(int label, int* returnSize){
    int *ans = malloc(100*sizeof(int));
    int level = log(label)/log(2);
    *returnSize = 0;
    findPath(ans, label, level, returnSize);
    return ans;
}



