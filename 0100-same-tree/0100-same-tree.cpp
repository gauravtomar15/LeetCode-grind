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
    bool func(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;
        bool r1 = func(p->left, q->left);
        bool r2 = func(p->right, q->right);
        if (r1 == true && r2 == true)
            return true;
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool isCheck = func(p, q);
        return isCheck;
    }
};