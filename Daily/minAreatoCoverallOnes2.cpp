#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
//intuition 2splitting lines give 3 triangles we can have 6 types of these all we neeed to do is find min from each category and finally compute min from all ;
    int minArea(int startRow,int endRow,int startCol,int endCol,vector<vector<int>>& arr){
        int r=arr.size();
        int c=arr[0].size();
        int minRow=r,minCol=c,maxRow=-1,maxCol=-1;
        for(int i=startRow;i<endRow;i++){
            for(int j=startCol;j<endCol;j++){
                 if(arr[i][j]==1){
                    minRow=min(minRow,i);
                    minCol=min(minCol,j);
                    maxRow=max(maxRow,i);
                    maxCol=max(maxCol,j);
                 }
            }
        }
        if(minRow>maxRow || minCol>maxCol) return 0;
        return ((maxRow-minRow+1)*(maxCol-minCol+1));
    }
    vector<vector<int>> rotated(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> temp(n,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 temp[j][m-i-1]=grid[i][j];
            }
        }
        return temp;
    }
    int utility(vector<vector<int>>& grid){
         int m=grid.size();
        int n=grid[0].size();
        int result=INT_MAX;
        for(int rowsplit=1;rowsplit<m;rowsplit++){
            for(int colsplit=1;colsplit<n;colsplit++){
                int top=minArea(0,rowsplit,0,n,grid);
                int bottomLeft=minArea(rowsplit,m,0,colsplit,grid);
                int bottomRight=minArea(rowsplit,m,colsplit,n,grid);
                result=min(result,top+bottomLeft+bottomRight);

                int topLeft=minArea(0,rowsplit,0,colsplit,grid);
                int topRight=minArea(0,rowsplit,colsplit,n,grid);
                int bottom=minArea(rowsplit,m,0,n,grid);
                 result=min(result,topLeft+topRight+bottom);
            }

        }

        for(int rowsplit1=1;rowsplit1<m;rowsplit1++){
            for(int rowsplit2=1;rowsplit2<m;rowsplit2++){
                int top=minArea(0,rowsplit1,0,n,grid);
                int mid=minArea(rowsplit1,rowsplit2,0,n,grid);
                int bottom=minArea(rowsplit2,m,0,n,grid);
                result=min(result,top+mid+bottom);
            }
        }
        return result;

    }
    int minimumSum(vector<vector<int>>& grid) {
        int result=utility(grid);
        vector<vector<int>> temp=rotated(grid);
        result=min(result,utility(temp));
        return result;
          
    }
};