#include <vector>
#include <algorithm>
using namespace std;
void buildTree(vector<int>& segmentTree,vector<int>& baskets,int i,int l,int r){
    if(l==r){
        segmentTree[i]=baskets[l];
        return;
    }
    int mid=(l+r)/2;
    buildTree(segmentTree,baskets,2*i+1,l,mid);
    buildTree(segmentTree,baskets,2*i+2,mid+1,r);
    segmentTree[i]=max(segmentTree[2*i+1],segmentTree[2*i+2]);
}
int findBasket(vector<int>& segmentTree,int fruit,int i,int l,int r){
        if(segmentTree[i]<fruit){
            return -1;
        }
        if(l==r) return l;
      int mid=(l+r)/2;
      int left=findBasket(segmentTree,fruit,2*i+1,l,mid);
      if(left!=-1) return left;
      return findBasket(segmentTree,fruit,2*i+2,mid+1,r);
}
int updateTree(vector<int>& segmentTree,int ind,int i,int l,int r){
    if(ind<l || ind>r) return segmentTree[i];
    if(l==r && l==ind){
        segmentTree[i]=INT_MIN;
        return segmentTree[i];
    }
    int mid=(l+r)/2;
    int left=updateTree(segmentTree,ind,2*i+1,l,mid);
    int right=updateTree(segmentTree,ind,2*i+2,mid+1,r);
    return segmentTree[i]=max(left,right);
}
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        vector<int> segmentTree(4*n,0);
        buildTree(segmentTree,baskets,0,0,n-1);
        int ans=0;
        for(int i=0;i<n;i++){
            int res=findBasket(segmentTree,fruits[i],0,0,n-1);
            if(res==-1) ans++;
            else updateTree(segmentTree,res,0,0,n-1);
        }
        return ans;
    }
};