class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        
        for(int i =0 ; i<n;i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
            indegree[dest]++;
        }
        queue<int> q;
        for(int node =0; node<V;node++){
            if(indegree[node]==0){
                q.push(node);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int newnode = q.front();
            q.pop();
            topo.push_back(newnode);
            for(int i =0 ; i<adj[newnode].size();i++){
                int neigh = adj[newnode][i];
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
           return topo;  
    }
};