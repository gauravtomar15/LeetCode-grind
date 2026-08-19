class Solution {
	public:
	class Node {
		public:
		int value;
		int row;
		int col;
		Node(int v, int r, int c) {
			value = v;
			row = r;
			col = c;
		}
	};
	struct cmp {
		bool operator()(const Node &a, const Node &b) {
			return a.value>b.value;
		}
	};
	vector<int> mergeArrays(vector<vector<int>> &mat) {
		int n = mat.size();
		int m = mat[0].size();
		priority_queue<Node, vector<Node>, cmp> pq;
		for (int i = 0 ; i<n; i++) {
			pq.push({mat[i][0], i, 0});
		}
		vector<int> res;
		while (!pq.empty()) {
			Node p = pq.top();
			pq.pop();
			int v = p.value;
			int row = p.row;
			int col = p.col;
			res.push_back(v);
			if (col<(m - 1)) {
				pq.push({mat[row][col + 1], row, col + 1 });
			}
		}
		return res;
	}
};
