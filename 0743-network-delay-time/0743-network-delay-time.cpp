class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, INT_MAX);
        for (int i = 0; i < times.size(); i++) {
            int source = times[i][0];
            int distance = times[i][1];
            int weight = times[i][2];
            adj[source - 1].push_back({distance - 1, weight});
        }
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, k - 1});
        dist[k - 1] = 0;

        while (!pq.empty()) {
            pair<int, int> t = pq.top();
            pq.pop();
            int node = t.second;
            int wt = t.first;
            if (wt > dist[node])
                continue;
            for (int i = 0; i < adj[node].size(); i++) {
                int neigh = adj[node][i].first;
                int newWt = adj[node][i].second;
                if (newWt + wt < dist[neigh]) {
                    dist[neigh] = newWt + wt;
                    pq.push({newWt + wt, neigh});
                }
            }
        }
        sort(dist.begin(), dist.end());
        int n1 = dist.size();
        if (dist[n - 1] == INT_MAX) {
            return -1;
        }
        return dist[n1 - 1];
    }
};