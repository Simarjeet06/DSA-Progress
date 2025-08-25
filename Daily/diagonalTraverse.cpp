#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        //  vector<int> ans(m*n);
        int i=0,j=0;
        bool up=true;
        vector<int> ans;
        ans.reserve(m*n);
        while(ans.size()<m*n){
            ans.push_back(mat[i][j]);
            if(up){
                if(j==n-1){
             i++;
             up=false;
                }
             else if(i==0){
                j++;
                up=false;
             }
             else{
                i--;
                j++;
             }
            } 
            else{
                if(i==m-1){
                    j++;
                    up=true;
                }
                else if(j==0){
                    i++;
                    up=true;
                }
                else{
                   i++;
                   j--;
                }
            }
        }
        return ans;
    // int r=0,c=0;
    // bool dir=1;
    // int i=0;
    // //dir==1 implies up and dir==0 implies down
    // while(r<m && c<n){
    //     ans[i++]=mat[r][c];
    //     int newr,newcol;
    //      if(dir==1){
    //         //if moving upwards i will decrement row and increment col
    //         newr=r-1;
    //         newcol=c+1;
    //      }
    //      else{
    //         //if moving downwards i will increment row and decrement col
    //         newr=r+1;
    //         newcol=c-1;
    //      }
    //      //within the bounds
    //      if(newr>=0 && newr<m && newcol>=0 && newcol<n){
    //         r=newr;
    //         c=newcol;
    //      }
    //      else{
    //         if(dir==1){
    //             if(c<n-1){
    //                 c++;
    //             }
    //             else{
    //                r++;
    //             }
    //         }
    //         else{
    //             if(r<m-1){
    //                 r++;
    //             }
    //             else{
    //                 c++;
    //             }
    //         }
    //          dir=!dir;
    //      }
         
    // }
    // return ans;
    }
    // }
};