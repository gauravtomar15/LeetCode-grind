class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < times.size(); i++) {
            int source = times[i][0];
            int distance = times[i][1];
            int weight = times[i][2];
            adj[source - 1].push_back({distance - 1, weight});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;
        pq.push({0, k - 1});
        while (!pq.empty()) {
            pair<int, int> t = pq.top();
            pq.pop();
            int d = t.first;
            int node = t.second;
            if (d > dist[node]) {
                continue;
            }
            for (int i = 0; i < adj[node].size(); i++) {
                int neigh = adj[node][i].first;
                int wt = adj[node][i].second;
                if (d + wt < dist[neigh]) {
                    dist[neigh] = d + wt;
                    pq.push({d + wt, neigh});
                }
            }
        }
        sort(dist.begin(), dist.end());
        int n1 = dist.size();
        if (dist[n1 - 1] == INT_MAX) {
            return -1;
        }
        return dist[n1 - 1];
    }
};