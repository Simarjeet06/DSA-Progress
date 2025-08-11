#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

void buildTree(vector<int>& segTree,vector<int>& heights,int i,int l,int r){
             if(l==r){
                segTree[i]=l;
                return;
             }
             int mid=l+((r-l)/2);
             buildTree(segTree,heights,2*i+1,l,mid);
             buildTree(segTree,heights,2*i+2,mid+1,r);
             int leftMaxIndex=segTree[2*i+1];
             int rightMaxIndex=segTree[2*i+2];
             if(heights[leftMaxIndex] >=heights[rightMaxIndex]){
                     segTree[i]=leftMaxIndex;
             }
             else segTree[i]=rightMaxIndex;
}

int querySegTree(vector<int>& segTree,vector<int>& heights,int start,int end,int i,int l,int r){
    if(end<l || start>r) return -1;
    if(l>=start && r<=end) return segTree[i];
    int mid=l+((r-l)/2);
    int left=querySegTree(segTree,heights,start,end,2*i+1,l,mid);
    int right=querySegTree(segTree,heights,start,end,2*i+2,mid+1,r);
    if(left==-1) return right;
    if(right==-1) return left;
    if(heights[left]>=heights[right]) return left;
    return right;
}



    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        vector<int> segTree(4*n,0);
        buildTree(segTree,heights,0,0,n-1);
        vector<int> result;
        for(auto& query : queries){
            int minIndex=min(query[0],query[1]);
            int maxIndex=max(query[0],query[1]);
            if(minIndex==maxIndex){
                // if alice and bob are  already present at the same building we have already have our answer
                result.push_back(minIndex);
                continue; // move to next query now since we have got our answer
            }
            else if(heights[maxIndex]>heights[minIndex]){
                 //if the rightmost of the two indices is max then the left most guy can jump to this and they can meet thus we have our answer 
                 result.push_back(maxIndex);
                 continue;
            }
            //now we need to compute the leftmost value for the right range 
            int l=maxIndex+1;
            int r=n-1;
            int resultIdx=INT_MAX;
            //binary search code
            while(l<=r){
                int mid=(l+((r-l)/2));
                int idx=querySegTree(segTree,heights,l,mid,0,0,n-1);
                if(heights[idx]>max(heights[minIndex],heights[maxIndex])){
                    resultIdx=idx;
                    r=mid-1;
                }
                else l=mid+1;
            }
            int ans=(resultIdx==INT_MAX)?-1:resultIdx;
            result.push_back(ans);
        }
        return result;
    }
};