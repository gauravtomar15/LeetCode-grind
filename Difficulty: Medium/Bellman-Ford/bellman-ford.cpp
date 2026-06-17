// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> res(V,1e8);
        res[src]=0;
        for(int i =0;i<V-1;i++){
            for(int j =0 ; j<edges.size();j++){
                int source = edges[j][0];
                int dist = edges[j][1];
                int weight = edges[j][2];
                if(res[source]!=1e8 && res[dist]>(res[source]+weight)){
                    res[dist]  = res[source]+weight;
                }
            }
        }
        for(int j =0 ; j<edges.size();j++){
                int source = edges[j][0];
                int dist = edges[j][1];
                int weight = edges[j][2];
                if(res[source]!=1e8 && res[dist]>(res[source]+weight)){
                    return {-1};
                }
            }
            return res;
    }
};
