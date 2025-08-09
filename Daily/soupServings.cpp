#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    double helper(int a,int b,vector<vector<double>>& dp){
        if(a<=0 && b<=0) return 0.5;
        if(a<=0 ) return 1;
        if(b<=0) return 0;
        a=max(a,0);
        b=max(b,0);
        if(dp[a][b]!=-1) return dp[a][b];
        double cs1=helper(a-100,b,dp);
        double cs2=helper(a-75,b-25,dp);
        double cs3=helper(a-50,b-50,dp);
        double  cs4=helper(a-25,b-75,dp);
     
     return dp[a][b]=0.25*(cs1+cs2+cs3+cs4);
    }
    double soupServings(int n) {
        n=(n+24)/25;
        if(n>=500) return 1.0;
        // if(n>=4800) return 1;
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1));
        // return helper(n,n,dp);
        dp[0][0]=0.5;
        for(int i=1;i<=n;i++){
          dp[0][i]=1.0;
            dp[i][0]=0.0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=0.25*(
                    dp[max(0,i-4)][j]+
                    dp[max(0,i-3)][max(0,j-1)]+
                    dp[max(0,i-2)][max(0,j-2)]+
                    dp[max(0,i-1)][max(0,j-3)]);
            }
        }
       return dp[n][n];
    }
};