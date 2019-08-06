/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
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
private:
    void _preorder(Node* root, vector<int>& ans) {
        if (!root) return;
        ans.push_back(root->val);
        if (root->children.size() > 0) {
            for (auto child : root->children)
                _preorder(child, ans);
        }
        
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        _preorder(root, ans);
        return ans;
    }
};
