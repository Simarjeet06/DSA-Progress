#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
     vector<int> vis;
     int dfs(int i,vector<vector<int>>& adj){
        vis[i]=true;
        int cnt=1;
        for(auto node:adj[i]){
            if(!vis[node]){
                cnt+=dfs(node,adj);
            }
        }
        return cnt;
     }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            long long xi=bombs[i][0];
            long long yi=bombs[i][1];
            long long ri=bombs[i][2];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                long long xj=bombs[j][0];
                long long yj=bombs[j][1];
                long long rj=bombs[j][2];
                long long dx=xi-xj;
                long long dy=yi-yj;
                if((dx*dx+dy*dy)<=1LL*ri*ri){
                    //if ((x2-x1)^2+(y2-y1)^2)<=r1^2 (so bomb2 lies in the vicinity of bomb1 and hence it can detonate it.)
                    adj[i].push_back(j);
                }
            }
        }
        vis.resize(n,false);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
           maxi=max(maxi,dfs(i,adj));
           vis.assign(n,false);
        }
        return maxi;
    }
};