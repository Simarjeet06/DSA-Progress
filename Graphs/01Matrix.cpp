#include<vector> 
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        int delRow[]={0,-1,0,1};
        int delCol[]={-1,0,1,0};
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            ans[r][c]=dist;
            for(int i=0;i<4;i++){
                int nr=r+delRow[i];
                int nc=c+delCol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]==1 && !vis[nr][nc]){
    
                    vis[nr][nc]=1;
                     q.push({{nr,nc},dist+1});
                    
                }
            }


        }
           return ans;
           
            }
};