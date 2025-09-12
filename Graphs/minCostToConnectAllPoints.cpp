#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    typedef pair<int,int> p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<bool> vis(n);
        //pq->{edw,index}
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            if(vis[ind]) continue;
            vis[ind]=true;
            sum+=wt;
            for(auto&v :adj[ind]){
                int adjNode=v.first;
                int edge=v.second;
                if(!vis[adjNode]){
                    pq.push({edge,adjNode});
                }
            }
        }
        return sum;

    }
};