#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid,int i,int j){
       if(i<0 || j<0) return 0;
       else if(grid[i][j]==1) return 0;
       else if(i==0 && j==0 ) return 1;
      
       return (solve(grid,i-1,j)+solve(grid,i,j-1));
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // dp.resize(m,vector<int>(n,0));
        // return solve(obstacleGrid,m-1,n-1);
        //state defn:- dp[i][j]->number of ways to reach  (i,j) from (0,0); since there is only 1 way to reach (0,0) from (0,0) so we return 1;
vector<int> prev(n,0),curr(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]) curr[j]=0;
                else if(i==0 && j==0 ){
                   curr[j]=1;
                }
                else{
                   int up=0,left=0;
                   if(i>0 && obstacleGrid[i][j]==0) up=prev[j];
                   if(j>0 && obstacleGrid[i][j]==0) left=curr[j-1];
                   curr[j]=up+left;
                }
            }
            prev=curr;
        }
        return curr[n-1];
    }
};