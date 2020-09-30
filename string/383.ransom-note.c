/*
 * @lc app=leetcode id=383 lang=c
 *
 * [383] Ransom Note
 */

// @lc code=start

// 在杂志上找需要的字母
bool canConstruct(char* ransomNote, char* magazine) {
    int arr[123] = {0};
    int i = 0, j = 0, k = 0;
    int mSize = strlen(ransomNote), nSize = strlen(magazine);
    for (i = 0; i < mSize; i++) arr[ransomNote[i]]++;
    for (j = 0; j < nSize; j++) arr[magazine[j]]--;
    for (k = 97; k < 123; k++)
        if (arr[k] > 0) return false;
    return true;
}
// @lc code=end
