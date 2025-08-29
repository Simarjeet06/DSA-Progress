#include<vector>
using namespace std;
class Solution {
public:
    int extraConnections=0;
    int findParent(int i,vector<int>& parent){
        if(parent[i]==i) return i;
        return parent[i]=findParent(parent[i],parent);
    }
    void unionBySize(int i,int j,vector<int>& parent,vector<int>& sized){
          int parenti=findParent(i,parent);
          int parentj=findParent(j,parent);
          if(parenti==parentj){
            extraConnections++;
            return;
          }
          if(sized[parenti]<sized[parentj]){
            parent[parenti]=parentj;
            sized[parentj]+=sized[parenti];
          }
          else{
            parent[parentj]=parenti;
            sized[parenti]+=sized[parentj];
          }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        vector<int> sized(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            unionBySize(u,v,parent,sized);  
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) cnt++;
        }
        //cnt depicts number of components and to connect x components we need a min of x-1 edges.
        cnt-=1;
        return (extraConnections>=cnt)?cnt:-1;
    }
};