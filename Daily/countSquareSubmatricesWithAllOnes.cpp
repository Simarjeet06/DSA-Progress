#include<vector>
using namespace std;
class Solution {
public:
   int m=0,n=0;
   vector<vector<int>> dp;
   int solve(int i,int j,vector<vector<int>>& matrix){
        if(i>=m  || j>=n) return 0;
        if(matrix[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        //dp[i][j]->gives max size square matrix possible ; also gives max number of square matrices consisting of 1
        int right=solve(i,j+1,matrix);
        int bottom=solve(i+1,j,matrix);
        int diag=solve(i+1,j+1,matrix);
        return dp[i][j]=1+min({right,diag,bottom});
   }
    int countSquares(vector<vector<int>>& matrix) {
         m=matrix.size();
         n=matrix[0].size();
         dp.resize(m+1,vector<int>(n+1,0));
         int result=0;
        //  memset(dp,sizeof(dp),-1);
        //in the bottom-up version we basically define dp[i][j]->number of submatrices filled with 1 such that matrix[i][j] is the last element or the bottom right element;
        for(int i=0;i<m;i++){
            if(matrix[i][0]==1){
                dp[i][0]=1;
                result+=dp[i][0];
            }
        }
        for(int j=1;j<n;j++){
            if(matrix[0][j]==1){
                dp[0][j]=1;
                result+=dp[0][j];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
               if(matrix[i][j]==1){
                // result+=solve(i,j,matrix);
                  dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                  result+=dp[i][j];
               }
            }
        }
        return result;

    }
};