#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> parent,sz;
    int findPar(int i){
        if(i==parent[i]) return i;
        return parent[i]=findPar(parent[i]);
    }
    void unionDo(int x,int y){
        int parentX=findPar(x);
        int parentY=findPar(y);
        if(parentX==parentY) return;
        if(sz[parentX]<sz[parentY]){
            parent[parentX]=parentY;
            sz[parentY]+=sz[parentX];
        }
        else{
            parent[parentY]=parentX;
            sz[parentX]+=sz[parentY];
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            unionDo(u,v);
        }
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            int pari=findPar(i);
             if(mpp.find(pari)==mpp.end()){
                mpp[pari]=sz[pari];             }
        }
        long long ans=((1LL*n*(n-1))/2);
        for(auto [comp,st]:mpp){
           ans-=(1LL*st*(st-1))/2;
        }
 return ans;
    }
};