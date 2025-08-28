#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
int m,n;
vector<vector<int>> t;
// long long solve(vector<vector<int>>& matrix,int i,int j){
//     if(i>=m || j>=n || j<0) return INT_MAX;
//     if(t[i][j]!=-1) return t[i][j];
//     if(i==m-1 && (j>=0 && j<n)) return matrix[i][j];
//     long long down=solve(matrix,i+1,j);
//     long long downLeft=solve(matrix,i+1,j-1);
//     long long downRight=solve(matrix,i+1,j+1);
//     return t[i][j]=matrix[i][j]+min({down,downLeft,downRight});
// }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
            // t.resize(m,vector<int>(n,0));
            //state defn:-min fallling path sum from (m-1)th row to 0th row
        // int mini=INT_MAX;
        // for(int i=0;i<n;i++){
        //     if(mini>solve(matrix,0,i)) mini=solve(matrix,0,i);
        // }
        // return mini;
vector<int> next=matrix[m-1];
        for(int i=m-2;i>=0;i--){
            vector<int> curr(n,INT_MAX);
            for(int j=0;j<n;j++){
                int down=next[j];
                int downLeft=INT_MAX,downRight=INT_MAX;
                if(j+1<n) downRight=next[j+1];
                if(j-1>=0) downLeft=next[j-1];
                curr[j]=matrix[i][j]+min({down,downRight,downLeft});
            }
            next=curr;
        }
      return *min_element(next.begin(),next.end());
    }
};