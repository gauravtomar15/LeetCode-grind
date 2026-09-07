/* Structure of Binary Tree Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	vector<int> leftView(Node *root) {
		// code here
		if (root == NULL) {
			return {};
		}
		vector<int> ans;
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			int n = q.size();
			
			for (int i = 0 ; i<n; i++) {
				Node* t = q.front();
				q.pop();
				if (i == 0) {
					ans.push_back(t->data);
				}
				if (t->left != NULL) {
					q.push(t->left);
				}
				if (t->right != NULL) {
					q.push(t->right);
				}
			}
			
		}
		return ans;
	}
};
