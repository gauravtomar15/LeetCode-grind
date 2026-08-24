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
    bool check(TreeNode* l1, TreeNode* l2) {
        if (l1 == NULL && l2 == NULL)
            return true;
        if (l1 == NULL || l2 == NULL)
            return false;
        if (l1->val != l2->val)
            return false;
        bool r1 = check(l1->left, l2->right);
        bool r2 = check(l1->right, l2->left);
        return r1 && r2;
    }
    bool isSymmetric(TreeNode* root) { return check(root->left, root->right); }
};