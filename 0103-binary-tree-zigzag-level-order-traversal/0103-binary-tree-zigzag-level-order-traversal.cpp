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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        bool leftToright = true;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            int first = 0;
            int last = levelSize - 1;
            vector<int> temp(levelSize);
            while (levelSize--) {
                TreeNode* t = q.front();
                q.pop();
                if (leftToright) {
                    temp[first] = t->val;
                    first++;
                } else {
                    temp[last] = t->val;
                    last--;
                }
                if (t->left != NULL) {
                    q.push(t->left);
                }
                if (t->right != NULL) {
                    q.push(t->right);
                }
            }
            leftToright = !leftToright;
            res.push_back(temp);
        }

        return res;
    }
};