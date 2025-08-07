#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
int child1Collection(int n,vector<vector<int>>& dp){
    int res=0;
    for(int i=1;i<n;i++){
        dp[i][i]+=dp[i-1][i-1];
    }
    return dp[n-1][n-1];
}
// int child2Collection(vector<vector<int>>& fruits,int i,int j,int n,vector<vector<int>>& dp){
//     if(i<0 || i>=n || j<0 || j>=n) return 0;
//     else if(i==n-1 && j==n-1) return 0;
//     else if(dp[i][j]!=-1) return dp[i][j];
//     int ni=i+1;
//     int maxi=0;
//     for(int col=-1;col<=1;col++){
//         int nj=j+col;
//         if(ni<nj){
//             maxi=max(maxi,child2Collection(fruits,ni,nj,n,dp));
//         }
//     }
//     return dp[i][j]=fruits[i][j]+maxi;
// }
// int child3Collection(vector<vector<int>>& fruits,int i,int j,int n,vector<vector<int>>& dp){
//     if(i<0 || i>=n || j<0 || j>=n) return 0;
//     else if(i==n-1 && j==n-1) return 0;
//     else if(dp[i][j]!=-1) return dp[i][j];
//     int nj=j+1;
//     int maxi=0;
//     for(int row=-1;row<=1;row++){
//         int ni=i+row;
//         if(ni>nj){
//             maxi=max(maxi,child3Collection(fruits,ni,nj,n,dp));
//         }
//     }
//     return dp[i][j]=fruits[i][j]+maxi;
// }

int child2Collection(int n,vector<vector<int>>& dp){
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int el1=(i+j-2>=n-1)?dp[i-1][j-1]:0;
            int el2=(i+j-1>=n-1)?dp[i-1][j]:0;
            int el3=(j+1<n && (i+j>=n-1))?dp[i-1][j+1]:0;
            dp[i][j]+=max({el1,el2,el3});
            cout<<dp[i][j]<<endl;
        }
    }
    return dp[n-2][n-1];

}

int child3Collection(int n,vector<vector<int>>& dp){
    for(int j=1;j<n-1;j++){
        for(int i=j+1;i<n;i++){
            int el1=((j+1<n) && (i+j-2>=n-1))?dp[i-1][j-1]:0;
            int el2=(i+j-1>=n-1)?dp[i][j-1]:0;
            int el3=((i+1<n && j+1<n) && (i+j>=n-1))?dp[i+1][j-1]:0;
            dp[i][j]+=max({el1,el2,el3});
        }
    }
    return dp[n-1][n-2];

}
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        vector<vector<int>> dp=fruits;
        int child1=child1Collection(n,dp);
        int child2=child2Collection(n,dp);
        dp=fruits;
        int child3=child3Collection(n,dp);
        cout<<child1<<" "<<child2<<" "<<child3<<endl;
        return (child1+child2+child3);
    }

};