/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

/*
// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    vector<vector<int>> res;

   public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return res;
        help(root, 0);
        return res;
    }

   private:
    void help(Node* root, int level) {
        if (res.size() == level) res.push_back({});
        res[level].push_back(root->val);
        for (auto a : root->children)
            help(a, level + 1);
    }
};
