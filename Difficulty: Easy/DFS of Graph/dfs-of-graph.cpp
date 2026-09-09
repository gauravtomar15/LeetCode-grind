class Solution {
	public:
	void dfs(vector<vector<int>> & adj, int node, vector<int>& res, vector<bool>& visited) {
		res.push_back(node);
		visited[node] = true;
		for (int i = 0 ; i<adj[node].size() ; i++) {
			int neigh = adj[node][i];
			if (visited[neigh] == false) {
				dfs(adj, neigh, res, visited);
			}
		}
		return;
	}
	vector<int> dfs(vector<vector<int>> & adj) {
		int n = adj.size();
		vector<int> res;
		vector<bool> visited(n, 0);
		dfs(adj, 0, res, visited);
		return res;
		
	}
};
