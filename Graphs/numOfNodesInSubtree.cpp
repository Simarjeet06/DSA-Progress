#include<vector>
#include<string>
using namespace std;
class Solution {
public:
vector<int> ans;
vector<vector<int>> adj;
vector<int> dfs(int node,int parent,string& labels){
    vector<int> freq(26,0);
    freq[labels[node]-'a']=1;
    for(int child:adj[node]){
        if(child==parent) continue;
        vector<int> childFreq=dfs(child,node,labels);
        for(int i=0;i<26;i++){
            freq[i]+=childFreq[i];
        }
    }
    ans[node]=freq[labels[node]-'a'];
    return freq;
}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.resize(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans.resize(n,1);
        vector<bool> vis(n,false);
       dfs(0,-1,labels);
        return ans;
    }
};