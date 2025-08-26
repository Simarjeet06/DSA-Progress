#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
  vector<vector<vector<int>>> dp;
  int threshold=0;
  int solve(vector<int>& prices,int n,int i,int cnt,int buy){
    if(i>=n) return 0;
    if(cnt<=0) return 0;
    if(dp[i][buy][cnt]!=-1) return dp[i][buy][cnt];
    int canBuy=0,sell=0;
    if(buy) canBuy=max(-prices[i]+solve(prices,n,i+1,cnt,!buy),solve(prices,n,i+1,cnt,buy));
    if(!buy) sell=max(prices[i]+solve(prices,n,i+1,cnt-1,!buy),solve(prices,n,i+1,cnt,buy));
    return dp[i][buy][cnt]=max(canBuy,sell);
  }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        threshold=k;
        //buy->1 , sell->0
        // dp.resize(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        //state defn:- max profit starting from day 0 and buy after completing k transactions
        // return solve(prices,n,0,k,true);
        vector<vector<int>> curr(2,vector<int>(k+1,0)),next(2,vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int cnt=1;cnt<=k;cnt++){
                curr[1][cnt]=max(-prices[i]+next[0][cnt],next[1][cnt]);
                curr[0][cnt]=max(prices[i]+next[1][cnt-1],next[0][cnt]);
            }
            next=curr;
        }
        //max profit starting from 0th day with buying state with cnt transactions left.
         //dp[i][j][k]->max profit starting from ith day with buy/sell and kth transactions left and since we need to return the start since we fill from bottom to top we return dp[0][1][k]
       return curr[1][k];
    }
};