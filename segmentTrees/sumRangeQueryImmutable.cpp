#include <vector>
using namespace std;
void buildTree(vector<int>& segmentTree,vector<int>& nums,int i,int l,int r){
    if(l==r){
        segmentTree[i]=nums[r];
        return;
    }
      int mid=l+(r-l)/2;
      buildTree(segmentTree,nums,(2*i)+1,l,mid);
      buildTree(segmentTree,nums,(2*i)+2,mid+1,r);
      segmentTree[i]=segmentTree[(2*i)+1]+segmentTree[(2*i)+2];
}
int query(vector<int>& segmentTree,int start,int end,int i,int l,int r){
    int mid=(l+r)/2;
    if(r<start || l>end) return 0;
    else if(l>=start && r<=end) return segmentTree[i];
        return query(segmentTree,start,end,2*i+1,l,mid)+query(segmentTree,start,end,2*i+2,mid+1,r);
    
}
class NumArray {
    vector<int> segmentTree;
    int numSize=0;
public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        numSize=n;
        segmentTree.resize(4 * n);
        buildTree(segmentTree,nums,0,0,n-1);
    }  
    int sumRange(int left, int right) {
        return query(segmentTree,left,right,0,0,numSize-1);

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */