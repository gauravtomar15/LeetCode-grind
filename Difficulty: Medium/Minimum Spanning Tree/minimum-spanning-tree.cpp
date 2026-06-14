class Solution {
	public:
	int spanningTree(int V, vector<vector<int>> & edges) {
		// code here
		vector<vector<pair<int, int>> > adj(V);
		for (int i = 0; i<edges.size(); i++) {
			int source = edges[i][0];
			int dest = edges[i][1];
			int weight = edges[i][2];
			adj[source].push_back({dest, weight});
			adj[dest].push_back({source, weight});
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		int sum = 0;
		vector<int> vis(V, 0);
		pq.push({0, 0});
		while (!pq.empty()) {
			pair<int, int> p = pq.top();
			pq.pop();
			int wt = p.first;
			int node = p.second;
			if (vis[node] == 1) {
				continue;
			}
			vis[node] = 1;
			sum = sum + wt;
			for (int i = 0 ; i<adj[node].size() ; i++) {
				int neigh = adj[node][i].first;
				int w = adj[node][i].second;
				if (vis[neigh] == 0) {
					pq.push({w, neigh});
				}
			}
		}
		return sum;
	}
};
