class Solution {
public:
   vector<vector<int>> ans;
   vector<int> disc,low;
   vector<bool> vis;
   vector<vector<int>> adj;
   int timer=0;
   void dfs(int u,int parent){
    vis[u]=true;
    disc[u]=low[u]=timer++;
    for(int v:adj[u]){
       if(v==parent) continue;
       else if(vis[v]){
        low[u]=min(low[u],disc[v]);
       }
       else{
        dfs(v,u);
        low[u]=min(low[u],low[v]);
        if(low[v]>disc[u]){
            //bridge exists
            // the lowest v can reach is not u as well so removing this edge will make graph disconnected
            ans.push_back({u,v});
        }
       }
    }

   }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        vis.resize(n,false);
        disc.resize(n,-1);
        low.resize(n,-1);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1);
        return ans;
    }
};