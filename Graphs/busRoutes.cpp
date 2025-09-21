class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        int n=routes.size();
        unordered_map<int,vector<int>> adj;
        for(int bus=0;bus<routes.size();bus++){
            for(int busStop:routes[bus]){
                adj[busStop].push_back(bus);
            }
        }
        queue<int> q;
        vector<bool> vis(n,false);
        for(int bus:adj[source]){
            //aa wali buses le skade ae taki aapa apne target wale bus stop te minimum buses leke pahuanch paiye
            vis[bus]=true;
            q.push(bus);
        }
        int busCnt=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
              int route=q.front();
              q.pop();
              for(int i=0;i<routes[route].size();i++){
                //hun aa bus leke kithe kithe uttar skde ae 
                int nextStop=routes[route][i];
                if(nextStop==target) return busCnt;
                for(int nextBus:adj[nextStop]){
                   if(!vis[nextBus]){
                    vis[nextBus]=true;
                    q.push(nextBus);
                   }
                }
              }
            }
            busCnt++;
        }
        return -1;
    }
};