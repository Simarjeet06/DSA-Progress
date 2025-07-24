#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
class Solution {
public:
  void dfs(int node,int parent,vector<int>& subTreeXor,vector<int>& inTime,vector<int>& outTime,int& timer,vector<int>& nums,unordered_map<int,vector<int>>& adj){
    subTreeXor[node]=nums[node];
    inTime[node]=timer;
    timer++;
    for(int neighbour:adj[node]){
        if(neighbour==parent) continue;
        else {
        dfs(neighbour,node,subTreeXor,inTime,outTime,timer,nums,adj);
        subTreeXor[node] ^= subTreeXor[neighbour];
        }
    }
    outTime[node]=timer;
    timer++;
  }
  //checking if ancestor is one of the nodes to be removed
  bool isAncestor(int u,int v,vector<int>& inTime,vector<int>& outTime){
    return (inTime[u]<inTime[v] && outTime[u]>outTime[v]);
  }
  int getScore(int xor1,int xor2,int xor3){
    int maxi=max({xor1,xor2,xor3});
    int mini=min({xor1,xor2,xor3});
    return maxi-mini;
  }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        //we are considering zero as root
        //number of nodes
        int n=nums.size();
       //adjacency list
       unordered_map<int,vector<int>> adj;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> subTreeXor(n,0);
        vector<int> inTime(n,0);
        vector<int> outTime(n,0);
        
        int timer=0;
        dfs(0,-1,subTreeXor,inTime,outTime,timer,nums,adj);
        int res=INT_MAX;
        for(int u=1;u<n;u++){
            for(int v=u+1;v<n;v++){

                int xor1=subTreeXor[u];
                int xor2=subTreeXor[v];
                int xor3=subTreeXor[0];

                if(isAncestor(u,v,inTime,outTime)){
                     xor1^= xor2;
                      xor3^=(xor1^xor2);
                }
                else if(isAncestor(v,u,inTime,outTime)){
                     xor2^=xor1;
                      xor3^=(xor1^xor2);
                }
                else{
                   xor1=subTreeXor[u];
                   xor2=subTreeXor[v];
                    xor3^=(xor1^xor2);
                }
                res=min(res,getScore(xor1,xor2,xor3));
            }
        }
        return res;
    }
};