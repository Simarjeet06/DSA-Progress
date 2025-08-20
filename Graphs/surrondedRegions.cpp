#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
int m=0,n=0;
int delRow[4]={-1,0,1,0};
int delCol[4]={0,-1,0,1};
   //so basically what we want to do is flip only those Os with X that are surronded by X in all 4 directions; but since border elements as O and Os connected with border Os are not connected with X in all 4 directions since should not be flipped.
   void dfs(int i,int j,vector<vector<char>>& board){
    board[i][j]='s';
    for(int k=0;k<4;k++){
        int r=i+delRow[k];
        int c=j+delCol[k];
        if(r>=0 && r<m && c>=0 && c<n){
            if(board[r][c]=='O'){
                dfs(r,c,board);
            }
        }
    }
   }
   void bfs(int i,int j,vector<vector<char>>& board){
      queue<pair<int,int>> q;
      q.push({i,j});
       board[i][j]='s';
      while(!q.empty()){
        auto it=q.front();
        q.pop();
        int r=it.first;
        int c=it.second;
        for(int k=0;k<4;k++){
            int nr=r+delRow[k];
            int nc=c+delCol[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O'){
                board[nr][nc]='s';
             q.push({nr,nc});
            }
        }
      }
   }
    void solve(vector<vector<char>>& board) {
         m=board.size();
         n=board[0].size();
         for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                bfs(i,0,board);
            }
            if(board[i][n-1]=='O'){
                bfs(i,n-1,board);
            }
         }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                bfs(0,j,board);
            }
            if(board[m-1][j]=='O'){
                bfs(m-1,j,board);
            }
         }
        
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='s') board[i][j]='O';
            }
         }

    }
};