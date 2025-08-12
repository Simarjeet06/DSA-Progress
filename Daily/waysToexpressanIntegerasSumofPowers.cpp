#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int f(int n,int x,int l,long long  r,int mod,vector<vector<int>>& dp){
        if(n==0) return 1;
        if(n<0 || l>r) return 0;
        if(dp[n][l]!=-1) return dp[n][l];
        int val=(pow(l,x));
         int pick=f(n-val,x,l+1,r,mod,dp);
         int skip=f(n,x,l+1,r,mod,dp);
        return dp[n][l]=((pick%mod)+(skip%mod))%mod;
    }
    int numberOfWays(int n, int x) {
        int l=1;
        long long r=round(pow(n,(1.0/x)));
        vector<vector<int>> dp(n+1,vector<int>(r+1,0));
        int mod=1e9+7;
        // return f(n,x,l,r,mod,dp);
        for(int i=1;i<=r;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<r;j++){
                    if(pow(j,x)>i) break;
                    long long val=pow(j,x);
                    int pick=dp[i-val][j+1];
                    int skip=dp[i][j+1];
                    dp[i][j]=((pick%mod)+(skip%mod))%mod;
            }
        }
        return dp[n][1];
    }
};