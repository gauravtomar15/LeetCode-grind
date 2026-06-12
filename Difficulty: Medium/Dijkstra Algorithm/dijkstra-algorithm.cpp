class Solution {
	public:
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
		// Code here
		vector<vector<pair<int, int>> > adj(V);
		for (int i = 0; i<edges.size(); i++) {
			int source = edges[i][0];
			int distance = edges[i][1];
			int weight = edges[i][2];
			adj[source].push_back({distance, weight});
			adj[distance].push_back({source,weight});
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		vector<int> dist(V, INT_MAX);
		dist[src] = 0;
		pq.push({0, src});
		while (!pq.empty()) {
			pair<int, int> t = pq.top();
			pq.pop();
			int d = t.first;
			int node = t.second;
			if (d>dist[node]) {
				continue;
			}
			for (int i = 0 ; i<adj[node].size(); i++) {
				int neigh = adj[node][i].first;
				int wt = adj[node][i].second;
				if (d + wt<dist[neigh]) {
					dist[neigh] = d + wt;
					pq.push({d + wt, neigh});
				}
			}
		}
		return dist;
	}
};
