#include<vector>
#include<string>
using namespace std;
class Solution {
public:
   vector<vector<int>> dp;
    int helper(string s,int i,int j){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=2+helper(s,i+1,j-1);
        return dp[i][j]=max(helper(s,i+1,j),helper(s,i,j-1));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        dp.resize(n,vector<int>(n,0));
        // dp[i][j]->length of longest palindromic subsequence for s[i..j] string starting from ith to jth index;
        //since we need the longest for the entire string out answer lies in t[0][n-1]
        for(int i=0;i<n;i++) dp[i][i]=1;

        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if(s[i]==s[j]) dp[i][j]=2+dp[i+1][j-1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);

            }
        }
        return dp[0][n-1];
    }
};