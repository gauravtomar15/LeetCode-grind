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
		if (root == NULL) {
			return {};
		}
		queue<pair<Node*, int>> q;
		map<int, int> mp;
		q.push({root, 0});
		vector<int> res;
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			Node* currNode = t.first;
			int currEl = t.second;
			mp[currEl] = currNode->data;
			if (currNode->left != NULL) {
				q.push({currNode->left, currEl - 1});
			}
			if (currNode->right != NULL) {
				q.push({currNode->right, currEl + 1});
			}
		}
		for (auto a : mp) {
			res.push_back({a.second});
		}
		return res;
	}
};
