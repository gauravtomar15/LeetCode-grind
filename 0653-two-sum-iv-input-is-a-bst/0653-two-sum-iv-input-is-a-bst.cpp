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
    stack<TreeNode*> asc;
    stack<TreeNode*> desc;
    // function to get next smallest element
    TreeNode* getSmall() {

        // top element is current smallest
        TreeNode* small = asc.top();
        asc.pop();

        // move to right subtree
        TreeNode* rightChild = small->right;

        // push all left nodes of right subtree
        while (rightChild) {
            asc.push(rightChild);
            rightChild = rightChild->left;
        }
        return small;
    }

    // function to get next largest element
    TreeNode* getLarge() {

        // top element is current largest
        TreeNode* big = desc.top();
        desc.pop();

        // move to left subtree
        TreeNode* leftChild = big->left;

        // push all right nodes of left subtree
        while (leftChild) {
            desc.push(leftChild);
            leftChild = leftChild->right;
        }
        return big;
    }
    bool findTarget(TreeNode* root, int k) {
        // edge case
        if (root == NULL) {
            return false;
        }

        TreeNode* t = root;

        // initialize ascending iterator
        // push all left nodes
        while (t) {
            asc.push(t);
            t = t->left;
        }
        t = root;

        // initialize descending iterator
        // push all right nodes
        while (t) {
            desc.push(t);
            t = t->right;
        }
        // smallest node
        TreeNode* i = getSmall();
        // largest node
        TreeNode* j = getLarge();
        // two pointer approach on BST
        while (i && j && i != j && i->val < j->val) {
            int sum = i->val + j->val;
            if (sum == k) {
                return true;
            }
            // need bigger sum
            else if (sum < k) {
                i = getSmall();
            }
            // need smaller sum
            else {
                j = getLarge();
            }
        }
        return false;
    }
};