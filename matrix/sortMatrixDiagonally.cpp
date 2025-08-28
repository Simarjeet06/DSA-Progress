#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        map<int,vector<int>> mpp;
        for(int row=0;row<m;row++){
           int i=row;
           int j=0;
           int ind=i-j;
           vector<int> temp;
           while(j<n && i<m){
            temp.push_back(mat[i][j]);
            j++;
            i++;
           }
           sort(temp.begin(),temp.end());
           mpp[ind]=temp;
        }
        for(int col=1;col<n;col++){
            int i=0;
            int j=col;
            int ind=i-j;
            vector<int> temp;
            while(i<m && j<n){
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(),temp.end());
            mpp[ind]=temp;
        }
        for(auto it=mpp.begin();it!=mpp.end();it++){
            auto ind=it->first;
            vector<int> temp=it->second;
            int i,j;
            if(ind>=0) i=ind,j=0;
            else i=0,j=-ind;
            for(int k=0;k<temp.size();k++){
                ans[i][j]=temp[k];
                i++;
                j++;
            }
        }
        return ans;
    }
};