/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   bool check(TreeNode*l , TreeNode*r){
    if(l==NULL && r==NULL){
        return true;
    }
    if(l==NULL || r==NULL){
        return false;
    }
    if(l->val!=r->val){
        return false;
    }
    bool r1 = check(l->left,r->right);
    bool r2 = check(l->right , r->left);
    return r1&&r2?true:false;

   }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
       bool ans =  check(root->left,root->right);
        return ans;
        
    }
};