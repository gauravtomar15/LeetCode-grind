/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    int solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return 0;
        }
        int l = solve(root->left, p, q);
        int r = solve(root->right, p, q);
        int sum = 0;
        if (root == p || root == q) {
            sum = 1;
        }
        int total = l + sum + r;
        if (total >= 2 && ans == NULL) {
            ans = root;
        }
        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
        return ans;
    }
};