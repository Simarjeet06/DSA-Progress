class DSU{
    public:
    vector<int> parent;
    vector<int> sz;
    int n;
    DSU(int n){
        this->n=n;
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        sz.resize(n,1);
    }
    int findParent(int n){
        if(parent[n]==n) return n;
        return parent[n]=findParent(parent[n]);
    }
    void unionSz(int x,int y){
        int parX=findParent(x);
        int parY=findParent(y);
        if(parX==parY) return;
        if(sz[parX]>=sz[parY]){
            parent[parY]=parX;
            sz[parX]+=sz[parY];
        }
        else{
            parent[parX]=parY;
            sz[parY]+=sz[parX];
        }
    }
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
      DSU dsu(c+1);
      unordered_map<int,set<int>> mpp;
      for(auto con:connections){
        dsu.unionSz(con[0],con[1]);
      }
      for(int i=1;i<=c;i++){
        mpp[dsu.findParent(i)].insert(i);
      }
      vector<int> ans;
      for(auto q:queries){
        if(q[0]==1){
         int p=dsu.findParent(q[1]);
         if(!mpp[p].empty() && mpp[p].count(q[1])){
            ans.push_back(q[1]);
         }
         else if(!mpp[p].empty()){
            auto it=mpp[p].begin();
            ans.push_back(*it);
         }
         else ans.push_back(-1);    
        }
        else{
            int node=q[1];
            int p=dsu.findParent(node);
            if(!mpp.empty() && mpp[p].find(node)!=mpp[p].end()){
                mpp[p].erase(node);
            }
        }
      }
      return ans;
    }
};