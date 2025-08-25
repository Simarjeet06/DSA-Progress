#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
// int dp[501][501];
    //  int solve(string& s1,string& s2,int i,int j,int m,int n){
    //     if(i==m || j==n){
    //         return (m-i)+(n-j);
    //     }
    //     if(t[i][j]!=-1) return t[i][j];
    //     if(s1[i]==s2[j]) return t[i][j]=solve(s1,s2,i+1,j+1,m,n);
    //     return t[i][j]=1+min(solve(s1,s2,i+1,j,m,n),solve(s1,s2,i,j+1,m,n));
    //  }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        // memset(dp,0,sizeof(dp));
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        //state defn:-min operations or deletions required to make word1(i..m) and word2(j..n) equal
        // return solve(word1,word2,0,0,m,n);
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         if(word1[i-1]==word2[j-1]){
        //             dp[i][j]=1+dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
        // return (m+n-2*(lcs));
        //if string 2 is exhausted number of characters in string 1 left will be the deletions required
        for(int i=0;i<m;i++) dp[i][n]=m-i;
        //if string2 is exhausted the number of characters left in string 1 will be the number of deletions required
        for(int j=0;j<n;j++) dp[m][j]=n-j;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(word1[i]==word2[j]) dp[i][j]=dp[i+1][j+1];
                else {
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};