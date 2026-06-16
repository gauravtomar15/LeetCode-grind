class Solution {
  public:
    void dfsTraverse(vector<vector<int>>& adj , int node, vector<int>&res, vector<int> &visitedNode){
        res.push_back(node);
        visitedNode[node]=1;
        for(int i =0 ; i<adj[node].size();i++){
            int neigh = adj[node][i];
            if(visitedNode[neigh]==0){
                dfsTraverse(adj,neigh,res,visitedNode);
            }
        }
        return ;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> res;
        vector<int> visitedNode(n,0);
        dfsTraverse(adj,0,res,visitedNode);
        return res;
        
    }
};