#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<int>> adj;
    int n;
    int maxi=0;
    int dfs(int node,int parentNode,string& s){
         int longest=0,secondLongest=0;
        for(int adjNode:adj[node]){
            if(adjNode==parentNode) continue;
            int length=dfs(adjNode,node,s);
            if(s[node]!=s[adjNode]){
                if(longest<length){
                    secondLongest=longest;
                    longest=length;
                }
                else if(length>secondLongest){
                    secondLongest=length;
                }
            }
        }
        maxi=max(maxi,1+longest+secondLongest);
        return 1+longest;
    }
    int longestPath(vector<int>& parent, string s) {
        n=parent.size();
        adj.resize(n);
        int rootIdx=-1;
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                rootIdx=i;
                continue;
            }
            int u=i;
            int v=parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,s);
        return maxi;
    }
};