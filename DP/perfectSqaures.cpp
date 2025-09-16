#include<vector>
#include<algorithm>
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
class Solution {
public:
int t[10001];
    int helper(int n){
        if(n==0) return 0;
        if(t[n]!=-1) return t[n];
        int mini=INT_MAX;
        for(int i=1;i*i<=n;i++){
            mini=min(mini,1+helper(n-i*i));
        }
        return t[n]=mini;
    }
    int numSquares(int n) {
        memset(t,-1,sizeof(t));
        // return helper(n);
        vector<int> dp(n+1,INT_MAX);
        //state defination:- minimum number of perfect squares that give a sum of n
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
             dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};