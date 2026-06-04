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
    unordered_map<int, int> mp;
    int idx = 0;
    TreeNode* func(vector<int>& preorder, int low, int high) {
        if (low > high)
            return NULL;
        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        int id = mp[node->val];
        node->left = func(preorder, low, id - 1);
        node->right = func(preorder, id + 1, high);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return func(preorder, 0, inorder.size() - 1);
    }
};