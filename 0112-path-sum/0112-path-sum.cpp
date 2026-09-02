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
    bool res = false;
    void check(TreeNode* root, int target, int sum) {
        if (root == NULL)
            return;
        sum = sum + root->val;
        if (root->left == NULL && root->right == NULL) {
            if (sum == target) {
                res = true;
                return;
            }
        }
        check(root->left, target, sum);
        check(root->right, target, sum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        check(root, targetSum, 0);
        return res;
    }
};