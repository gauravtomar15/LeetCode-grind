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
    int res = 0;
    int findMax(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = findMax(root->left);
        int right = findMax(root->right);
        int sum = left + right;
        res = max(res, sum);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        findMax(root);
        return res;
    }
};