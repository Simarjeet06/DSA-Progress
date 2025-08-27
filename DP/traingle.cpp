#include<vector>
using namespace std;
class Solution {
public:
    int m;
    // long long solve(vector<vector<int>>& triangle,int i,int j){
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(i==m-1) return triangle[i][j];
    //     int down=solve(triangle,i+1,j);
    //     int downRight=solve(triangle,i+1,j+1);
    //     return dp[i][j]=triangle[i][j]+min(down,downRight);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
         m=triangle.size();
        //  memset(dp,0,sizeof(dp));
        //  return solve(triangle,0,0);
        // vector<vector<int>> dp(m,vector<int>(m,INT_MAX));
        int last=triangle[m-1].size();
        vector<int> next(last);
        for(int j=0;j<triangle[m-1].size();j++) next[j]=triangle[m-1][j];
        for(int i=m-2;i>=0;i--){
            vector<int> curr(triangle[i].size(),0);
            for(int j=triangle[i].size()-1;j>=0;j--){
                int downRight=next[j+1];
                int down=next[j];
                curr[j]=triangle[i][j]+min(down,downRight);

            }
            next=curr;
        }
       
        return next[0];

        
    }
};