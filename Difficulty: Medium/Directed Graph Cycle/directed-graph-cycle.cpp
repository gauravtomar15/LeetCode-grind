class Solution {
  public:
    bool cycle = false;
    void dfs(vector<vector<int>> &adj, int node , vector<bool> &path, vector<bool> &vis){
        path[node]=true;
        vis[node]= true;
        for(int i =0 ; i<adj[node].size();i++){
            int neigh = adj[node][i];
            if(vis[neigh]==true && path[neigh]==true){
                cycle = true;
            } 
            if(vis[neigh]==false){
                dfs(adj,neigh,path,vis);
            }
        }
        path[node] = false;
        return ;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<bool> path(V,false);
        vector<bool> vis(V,false);
        vector<vector<int>> adj(V);
        
        for(int i =0 ; i<edges.size();i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
        }
        for(int j =0 ;j<V;j++){
            if(!vis[j]){
                dfs(adj,j,path,vis);
            }
        }
        return cycle;
    }
};