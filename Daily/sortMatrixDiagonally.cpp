#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
 vector<vector<int>> ans;
 int n;
    void sortDiagonal(int row,int col,vector<vector<int>>& grid,bool asc){
        int i=row;
        int j=col;
        vector<int> temp;
        while(i<n && j<n){
              temp.push_back(grid[i][j]);
              i++;
              j++;
        }
        if(asc) sort(begin(temp),end(temp));
        else sort(rbegin(temp),rend(temp));
        for(int el:temp){
            ans[row++][col++]=el;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
         n=grid.size();
        ans.resize(n,vector<int>(n));
        // for(int row=0;row<n;row++){
        //    sortDiagonal(row,0,grid,false);
        // }
        // for(int col=1;col<n;col++){
        //     sortDiagonal(0,col,grid,true);
        // }
        // return ans;
        map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int ind=i-j;
                mpp[ind].push_back(grid[i][j]);
            }
        }
        for(auto it=mpp.begin();it!=mpp.end();it++){
            int ind=it->first;
            //we are sorting in opp to what is asked so that we can access the last element in 0(1) and delete it 
            if(ind>=0) sort(begin(mpp[ind]),end(mpp[ind]));
            else sort(rbegin(mpp[ind]),rend(mpp[ind]));

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int ind=i-j;
                ans[i][j]=mpp[ind].back();
                mpp[ind].pop_back();
            }
        }
        return ans;
    }
};