#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int extra=0;
    vector<vector<int>> dp;
    int solve(vector<int>& prices,int i,int buy,int n){
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int canBuy=0,sell=0;
        if(buy){
            canBuy=max(-prices[i]+solve(prices,i+1,!buy,n),solve(prices,i+1,buy,n));
        }
        else{
            sell=max(prices[i]-extra+solve(prices,i+1,!buy,n),solve(prices,i+1,buy,n));
        }
        return dp[i][buy]=max(canBuy,sell);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        extra=fee;
        // dp.resize(n+1,vector<int>(2,0));
        // return solve(prices,0,1,n);
        vector<int> curr(2,0),next(2,0);
        for(int i=n-1;i>=0;i--){
            curr[1]=max(-prices[i]+next[0],next[1]);
            curr[0]=max(prices[i]-fee+next[1],next[0]);
            next=curr;
        }
        return curr[1];
    }
};