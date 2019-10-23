/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
class Solution {
    vector<string> ret;
    void backtrack(int left, int right, string p) {
        if (left < 0 || right < 0 || left > right) return;
        if (left == 0 && right == 0)
            ret.push_back(p);
        backtrack(left - 1, right, p + '(');
        backtrack(left, right - 1, p + ')');
    }

   public:
    vector<string> generateParenthesis(int n) {
        ret.clear();
        backtrack(n, n, "");
        return ret;
    }
};