#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> segTree;
    int l=0,r=0;
    void buildTree(vector<int>& nums,int i,int l,int r){
        if(l==r){
            segTree[i]=nums[l];
            return;
        }
        int mid=(l+r)>>1;
        buildTree(nums,2*i+1,l,mid);
        buildTree(nums,2*i+2,mid+1,r);
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];

    }
    NumArray(vector<int>& nums) {
        int n=nums.size();
        segTree.resize(4*n,0);
        r=n-1;
        buildTree(nums,0,l,r);
    }
    int query(int start,int end,int i,int l,int r){
        if(end<l || start>r || l>r) return 0;
        if(start>=l && end<=r){
            return segTree[i];
        }
        int mid=(l+r)>>1;
        return query(start,end,2*i+1,l,mid)+query(start,end,2*i+2,mid+1,r);
    }
    void updateQuery(int i,int index,int val,int l,int r){
        if(l==r){
            segTree[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(index<=mid){
             updateQuery(2*i+1,index,val,l,mid);
        }
        else{
            updateQuery(2*i+2,index,val,mid+1,r);
        }
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    
    void update(int index, int val) {
        updateQuery(0,index,val,l,r);
    }
    
    int sumRange(int left, int right) {
        return query(left,right,0,l,r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */