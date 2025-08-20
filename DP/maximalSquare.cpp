#include<vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        // vector<vector<int>> t(m+1,vector<int>(n+1,0));
        vector<int> prev(n,0);
        int result=0;
       // t[i][j]->defines the max size of square matrix for which the matrix[i][j] forms the bottom right corner of square submatrix filled with 1's;
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
               if(matrix[i][j]=='1'){
                if(i==0 || j==0) curr[j]=1;
               else  curr[j]=1+min({prev[j],prev[j-1],curr[j-1]});
                result=max(result,curr[j]);
               }
            }
          prev=curr;
        }
        return result*result;
    }
};