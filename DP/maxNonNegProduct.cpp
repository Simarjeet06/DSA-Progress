#include<vector>
using namespace std;
class Solution {
public: 
typedef long long ll;
int m,n;
int mod=1e9+7;
vector<vector<pair<ll,ll>>> dp;
//since we have negative numbers as well we need to keep track of both min and max as a negative number muktiplied with a min value might result in a better pos max result; hence keeping track of both is important.       
pair<ll,ll> solve(int i,int j,vector<vector<int>>& grid){
    if(i==m-1 && j==n-1) return {grid[i][j],grid[i][j]};
    if(dp[i][j]!= make_pair(LLONG_MAX,LLONG_MIN)) return dp[i][j];
    ll minVal=LLONG_MAX;
    ll maxVal=LLONG_MIN;
    //down
    if(i+1<m){
    auto[downMin,downMax]=solve(i+1,j,grid);
    minVal=min({minVal,downMin*grid[i][j],downMax*grid[i][j]});
    maxVal=max({maxVal,downMin*grid[i][j],downMax*grid[i][j]});
    }
    //right
    if(j+1<n){
    auto[rightMin,rightMax]=solve(i,j+1,grid);
    minVal=min({minVal,rightMin*grid[i][j],rightMax*grid[i][j]});
    maxVal=max({maxVal,rightMin*grid[i][j],rightMax*grid[i][j]});
    }
    return dp[i][j]={minVal,maxVal};
}
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.resize(m,vector<pair<ll,ll>>(n,{LLONG_MAX,LLONG_MIN}));
        // pair<ll,ll> final=solve(0,0,grid);
        //state defn:- dp[i][j]->(minVal,maxVal) while moving from(0,0) to (i,j)
        dp[0][0]=make_pair(grid[0][0],grid[0][0]);
        for(int i=1;i<m;i++){
            ll topMin=dp[i-1][0].first;
            ll topMax=dp[i-1][0].second;
            ll mini=topMin*grid[i][0];
            ll maxi=topMax*grid[i][0];
          dp[i][0]={mini,maxi};
        }
        for(int j=1;j<n;j++){
            ll leftMin=dp[0][j-1].first;
            ll leftMax=dp[0][j-1].second;
            ll mini=leftMin*grid[0][j];
            ll maxi=leftMax*grid[0][j];
          dp[0][j]={mini,maxi};
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                 auto [topMin,topMax]=dp[i-1][j];
                 auto [leftMin,leftMax]=dp[i][j-1];
                 ll maxi=max({grid[i][j]*leftMax,grid[i][j]*leftMin,grid[i][j]*topMin,grid[i][j]*topMax});
                 ll mini=min({grid[i][j]*leftMin,grid[i][j]*leftMax,grid[i][j]*topMin,grid[i][j]*topMax});
                 dp[i][j]={mini,maxi};
            }
        }
        ll final=dp[m-1][n-1].second;
        return (final<0)?-1:(final)%mod; 
    }
};