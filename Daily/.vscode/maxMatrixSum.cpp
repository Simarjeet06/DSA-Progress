class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int mini=INT_MAX,countNeg=0;
        for(auto& row:matrix){
            for(int v:row){
                mini=min(mini,abs(v));
                if(v<0) countNeg++;
               sum+=abs(v);
        }
    }
    return (countNeg & 1 )?sum-2LL*mini:sum;
    }
};