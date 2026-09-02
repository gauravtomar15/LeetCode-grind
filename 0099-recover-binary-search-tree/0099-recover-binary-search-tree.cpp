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
    TreeNode* prev = NULL;
    TreeNode* g1first = NULL;
    TreeNode* g1second = NULL;
    TreeNode* g2first = NULL;
    TreeNode* g2second = NULL;
    int galat = 0;

    void solve(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        solve(root->left);
        if (prev == NULL) {
            prev = root;
        } else {
            if (prev->val > root->val) {
                if (galat == 0) {
                    g1first = prev;
                    g1second = root;
                    galat++;
                } else {
                    g2first = prev;
                    g2second = root;
                    galat++;
                }
            }
            prev = root;
        }
        solve(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        if (galat == 1) {
            swap(g1first->val, g1second->val);
        } else {
            swap(g1first->val, g2second->val);
        }
        return;
    }
};