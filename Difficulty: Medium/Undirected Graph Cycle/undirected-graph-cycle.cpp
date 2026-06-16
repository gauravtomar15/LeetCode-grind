class Solution {
	public:
	bool hasCycle = false;
	void dfs(vector<vector<int>> &adj, int node, int V, int parentNode, vector<bool> &vis) {
		vis[node] = true;
		for (int i = 0; i<adj[node].size(); i++) {
			int neigh = adj[node][i];
			if (vis[neigh] == true && parentNode != neigh) {
				hasCycle = true;
			}
			if (vis[neigh] == false) {
				dfs(adj, neigh, V, node, vis);
			}
		}
		return ;
	}
	bool isCycle(int V, vector<vector<int>> & edges) {
		// Code here
		int n = edges.size();
		vector<vector<int>> adj(V);
		for (int i = 0 ; i<n; i++) {
			int src = edges[i][0];
			int dest = edges[i][1];
			adj[src].push_back(dest);
			adj[dest].push_back(src);
		}
		vector<bool> vis(V, false);
		for (int node = 0; node<V; node++) {
			if (vis[node] == false) {
				dfs(adj, node, V, -1, vis);
			}
		}
		return hasCycle;
	}
};
