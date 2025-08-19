#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        int time=-1;
        int delRow[]={0,-1,0,1};
        int delCol[]={-1,0,1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        while(!q.empty()){
            int st=q.size();
             time++;
            while(st--){
                auto [r,c]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=r+delRow[i];
                    int ncol=c+delCol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                        grid[nrow][ncol]=2;
                        q.push({nrow,ncol});
                        fresh--;

                    }
                }

            }
        }
        return (fresh==0)?time:-1;
    }
};