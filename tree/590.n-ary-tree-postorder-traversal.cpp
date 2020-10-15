/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
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
    void _postorder(Node* root, vector<int>& ans) {
        if (!root) return;
        if (root->children.size() > 0) {
            for (auto child : root->children)
                _postorder(child, ans);
        }
        ans.push_back(root->val);
    }

   public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        _postorder(root, ans);
        return ans;
    }
};
