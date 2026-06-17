class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i =0;i<edges.size();i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            int weight = edges[i][2];
            adj[src].push_back({dest,weight});
            adj[dest].push_back({src,weight});
        }
        using p = pair<int,int>;
        priority_queue<p,vector<p> , greater<p>> pq;
        pq.push({0,0});
        vector<int> vis(V,0);
        int sum =0;
        while(!pq.empty()){
            pair<int,int> t = pq.top();
            pq.pop();
            int node = t.second;
            int wt = t.first;
            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            sum = sum+wt;
            for(int j =0;j<adj[node].size(); j++){
                int neigh = adj[node][j].first;
                int newWt = adj[node][j].second;
                if(vis[neigh]==0){
                    pq.push({newWt,neigh});
                }
            }
        }
        return sum;
    }
};