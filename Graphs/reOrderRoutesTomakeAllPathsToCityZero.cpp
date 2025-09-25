class Solution {
public:
    int tobeFlipped=0;
    vector<vector<pair<int,bool>>> adj;
    void dfs(int node,int parent){
        for(auto [adjNode,isOriginal]:adj[node]){
            if(adjNode==parent) continue;
            if(isOriginal) tobeFlipped++;
            dfs(adjNode,node);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        //first we create an adjacency list where we store the all connections plus additional edges so that we can visit all nodes.we use a bool variable to store the information if the edge is original or newly created.
        adj.resize(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back({v,true});
            adj[v].push_back({u,false});
        }
        //now we start our traversal
        dfs(0,-1);
        return tobeFlipped;
    }
};