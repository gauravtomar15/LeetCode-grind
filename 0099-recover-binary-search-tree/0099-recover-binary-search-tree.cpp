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
    TreeNode* g1f = NULL;
    TreeNode* g1s = NULL;
    TreeNode* g2f = NULL;
    TreeNode* g2s = NULL;
    int galat = 0;
    void check(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        check(root->left);
        if (prev == NULL) {
            prev = root;
        } else {
            if (root->val < prev->val) {
                if (galat == 0) {
                    g1f = prev;
                    g1s = root;
                    galat++;
                } else {
                    g2f = prev;
                    g2s = root;
                    galat++;
                }
            }
            prev = root;
        }
        check(root->right);
    }
    void recoverTree(TreeNode* root) {
        check(root);
        if (galat == 1) {
            swap(g1f->val, g1s->val);
        } else {
            swap(g1f->val, g2s->val);
        }
        return;
    }
};