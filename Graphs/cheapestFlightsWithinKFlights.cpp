#include<vector>
#include<queue>
#include<climits>
#include<iostream>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dist(n+1,INT_MAX);
        dist[src]=0;
        for(auto vec:flights){
            int start=vec[0];
            int end=vec[1];
            int price=vec[2];
            adj[start].push_back({end,price});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int travelCost=it.second.second;
            if(stops>k) continue;
            for(auto v:adj[node]){
                int adjNode=v.first;
                int wt=v.second;
                if((travelCost+wt<dist[adjNode]) && (stops<=k)){
                    cout<<stops<<" "<<dist[node]+wt<<endl;
                           dist[adjNode]=travelCost+wt;
                           q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
            if(dist[dst]==INT_MAX) return -1;
            return dist[dst];
        
    }
};