#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
     vector<vector<int>> dp;
    int solve(vector<int>& prices,int buy,int i,int n){
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int canBuy=0,sell=0,skip=0;
        // buy==1->canBuy, buy==0->sell
        if(buy==1){
            canBuy=max(-prices[i]+solve(prices,0,i+1,n),solve(prices,1,i+1,n));
        }
       else if(buy==0)  sell=max(prices[i]+solve(prices,2,i+1,n),solve(prices,0,i+1,n));
       else  skip=solve(prices,1,i+1,n);
        return dp[i][buy]=max({canBuy,sell,skip});
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // dp.resize(n+1,vector<int>(3,0));
        //buy==1->can hold,buy==0->can sell,buy==2->cooldown
        // return solve(prices,1,0,n);
    //rather than keeping 3 values assigned for buy,sell,and cooldown we can use the concept that after a buy we skip the next day and directly move to i+2 day and hence we define dp array of size n+2 since we might  i+2 index for cooldown case
    // dp.resize(n+2,vector<int>(2,0));
    vector<int> curr(2,0),next1(2,0),next2(2,0);
    for(int i=n-1;i>=0;i--){
        //1->buy and 0->sell
        curr[1]=max(-prices[i]+next1[0],next1[1]);
        curr[0]=max(prices[i]+next2[1],next1[0]);
        next2=next1;
        next1=curr;
    }
    return curr[1];

    }
};