/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isNull = false;
    bool check(TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t == NULL) {
                isNull = true;
            } else {
                if (isNull) {
                    return false;
                }
                q.push(t->left);
                q.push(t->right);
            }
        }

        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        bool ans = check(root);
        return ans;
    }
};