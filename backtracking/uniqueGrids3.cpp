#include<vector>
using namespace std;
class Solution {
public:
    int m,n;
    int result,nonObstacles;
    vector<vector<int>> directions={{0,-1},{-1,0},{0,1},{1,0}};
    void backtrack(vector<vector<int>>& grid,int r,int c,int cnt){
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]==-1) return;
        else if(grid[r][c]==2){
            if(cnt==nonObstacles)
                result+=1;
                return;
            
        }
        grid[r][c]=-1;
        for(auto& d: directions){
           int new_r=r+d[0];
           int new_c=c+d[1];
           backtrack(grid,new_r,new_c,cnt+1);
        }
        grid[r][c]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        result=0;
        nonObstacles=0;
        int cnt=0;
        int start_i=-1,start_j=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==1){
                start_i=i;
                start_j=j;
               }
               else if(grid[i][j]==0){
                nonObstacles++;
               }
            }
        }
        nonObstacles+=1;
        backtrack(grid,start_i,start_j,0);
        return result;
    }
};