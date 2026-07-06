/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
           if (root == NULL) return {};

        vector<int> result;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                if (i == 0) {
                    result.push_back(curr->data);
                }

                if (curr->left != NULL) q.push(curr->left);
                if (curr->right != NULL) q.push(curr->right);
            }
        }

        return result;
    }
};