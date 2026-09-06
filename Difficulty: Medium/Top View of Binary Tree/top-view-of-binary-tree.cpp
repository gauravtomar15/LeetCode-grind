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
	vector<int> topView(Node *root) {
		// code here
		if (root == NULL) {
			return {};
		}
		queue<pair<Node*, int>> q;
		q.push({root, 0});
		int verticalValue = 0;
		map<int, int> mp;
		mp[verticalValue] = root->data;
		vector<int> res;
		while (!q.empty()) {
			int n = q.size();
			while (n--) {
				auto t = q.front();
				q.pop();
				Node* currRoot = t.first;
				int verticalValue = t.second;
				if (mp.find(verticalValue) == mp.end()) {
					mp[verticalValue] = currRoot->data;
				}
				if (currRoot->left != NULL) {
					q.push({currRoot->left, verticalValue - 1});
				}
				if (currRoot->right != NULL) {
					q.push({currRoot->right, verticalValue + 1});
				}
			}
		}
		for (auto a: mp) {
			res.push_back(a.second);
		}
		return res;
	}
};
