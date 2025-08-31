#include<vector>
using namespace std;
class Solution {
public:
    bool row[9][10]={false};
    bool col[9][10]={false};
    bool box[9][10]={false};
    vector<vector<char>> ans;
    void solve(vector<vector<char>>& board,vector<pair<int,int>>& empties,int pos){
        if(pos==empties.size()){
            ans=board;
            return;
        }
        int r=empties[pos].first;
        int c=empties[pos].second;
        int b=3*(r/3)+(c/3);
        for(int d=1;d<=9;d++){
             if(!row[r][d] && !col[c][d] && !box[b][d]){
                row[r][d]=true;
                col[c][d]=true;
                box[b][d]=true;
                board[r][c]=char(d+'0');
                solve(board,empties,pos+1);
                if(!ans.empty()) return;
                row[r][d]=false;
                col[c][d]=false;
                box[b][d]=false;
                board[r][c]='.';
             }
        }
    }
    bool isValid(vector<vector<char>>& board,int r,int c,char d){
        for(int i=0;i<9;i++){
              if(board[i][c]==d) return false;
              if(board[r][i]==d) return false;
        }
              int start_r=(r/3)*3;
              int start_c=(c/3)*3;
              for(int i=0;i<=2;i++){
                for(int j=0;j<=2;j++){
                    if(board[start_r+i][start_c+j]==d) return false;
                }
              }
              return true;
        
    }
    bool solved(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char d='1';d<='9';d++){
                        if(isValid(board,i,j,d)){
                            board[i][j]=d;
                            if(solved(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // vector<pair<int,int>> empties;
        
        // for(int i=0;i<9;i++){
        //     for(int j=0;j<9;j++){
        //         if(board[i][j]=='.'){
        //            empties.push_back({i,j});
        //         }
        //         else{
        //              int b=(3*(i/3))+(j/3);
        //              int val=board[i][j]-'0';
        //              row[i][val]=1;
        //              col[j][val]=1;
        //              box[b][val]=1;
        //         }
        //     }
        // }
        // solve(board,empties,0);
        // board=ans;
        solved(board);
    
    }
};