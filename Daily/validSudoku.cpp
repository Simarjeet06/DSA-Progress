#include<vector>
#include<unordered_set>
#include<string>
using namespace std;    

class Solution {
public:
    bool validBox(vector<vector<char>>& board,int sr,int sc,int er,int ec){
        unordered_set<char> st;
        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                   if(board[i][j]=='.') continue;
                if(st.find(board[i][j])!=st.end()) return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // //valid row
        // for(int i=0;i<9;i++){
        //     unordered_set<char> st;
        //     for(int j=0;j<9;j++){
        //         if(board[i][j]=='.') continue;
        //         if(st.find(board[i][j])!=st.end()) return false;
        //         st.insert(board[i][j]);
        //     }
        // }
        // //valid column
        // for(int j=0;j<9;j++){
        //     unordered_set<char> st;
        //     for(int i=0;i<9;i++){
        //         if(board[i][j]=='.') continue;
        //         if(st.find(board[i][j])!=st.end()) return false;
        //         st.insert(board[i][j]);
        //     }
        // }
        // //validbox
        // for(int sr=0;sr<9;sr+=3){
        //     int er=sr+2;
        //     for(int sc=0;sc<9;sc+=3){
        //      int ec=sc+2;
        //      if(! validBox(board,sr,sc,er,ec)) return false;
        //     }
        // }
        // return true;
        unordered_set<string> st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int boxNum=(i/3)*3+(j/3);
                string row="r"+to_string(i)+board[i][j];
                string col="c"+to_string(j)+board[i][j];
                string box="b"+to_string(boxNum)+board[i][j];
                if(st.find(row)!=st.end() || st.find(col)!=st.end() || st.find(box)!=st.end()) return false;
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }
};