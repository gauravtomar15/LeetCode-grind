/*
Definition for Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	vector<int> bottomView(Node *root) {
		// code here
		
		vector<int> ans;
		if (root == NULL) {
			return ans;
		}
		queue<pair<Node*, int>> q;
		map<int, int> mp;
		
		q.push({root, 0});
		while (!q.empty()) {
			auto it = q.front();
			q.pop();
			Node* currNode = it.first;
			int line = it.second;
			mp[line] = currNode->data;
			if (currNode->left != NULL) {
				q.push({currNode->left, line - 1});
			}
			if (currNode->right != NULL) {
				q.push({currNode -> right, line + 1});
			}
		}
		for (auto a : mp) {
			ans.push_back(a.second);
		}
		return ans;
	}
};
