#include<vector>
using namespace std;
class Solution {
public:
    int m,n;
    vector<vector<int>> directions={{1,1},{1,-1},{-1,-1},{-1,1}};
    int solve(int i,int j,int ind,vector<vector<int>>& grid,bool canTurn,int val){
       int newi=i+directions[ind][0];
       int newj=j+directions[ind][1];
       if(newi<0 || newi>=m || newj<0 || newj>=n || grid[newi][newj]!=val) return 0;
       int turn=0;
       int keepMoving=1+solve(newi,newj,ind,grid,canTurn,(val==2)?0:2);
       if(canTurn){
        turn=1+solve(newi,newj,(ind+1)%4,grid,false,(val==2)?0:2);
       }
       return max(keepMoving,turn);
    }
    
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int ind=0;ind<=3;ind++){
                         result=max(result,1+solve(i,j,ind,grid,true,2));
                    }
                }
            }
        }
        return result;
    }
};