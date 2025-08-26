#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    // vector<string> temp;
    // void solve(string s,int start,vector<vector<int>>& dp,int n,int& mini){
    //       if(start>=n){
    //          mini=min(mini,static_cast<int>(temp.size()-1));
    //          return;
    //       }
    //       for(int end=start;end<n;end++){
    //         if(dp[start][end]==1){
    //             temp.push_back(s.substr(start,end-start+1));
    //             solve(s,end+1,dp,n,mini);
    //             temp.pop_back();
    //         }
    //       }
    // }
    int t[2001][2001];
    int solve(string s,int i,int j,vector<vector<int>>& dp,int n){
        if(i>=j) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(dp[i][j]==1) return 0;
        int cut=INT_MAX;
        for(int k=i;k<j;k++){
           int  temp=1+solve(s,i,k,dp,n)+solve(s,k+1,j,dp,n);
            cut=min(temp,cut);
        
        }
        return t[i][j]=cut;
    }
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        //state defn:- dp[i][j]->s(i..j) is palindrome or not
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if(j==i+1) dp[i][j]=(s[i]==s[j]);
                else dp[i][j]=((s[i]==s[j]) && (dp[i+1][j-1]));
            }
        }
        // memset(t,-1,sizeof(t));
        // return solve(s,0,n-1,dp,n);
        vector<int> w(n+1,INT_MAX);
        // w[i] state defination-> min cuts to make all substrings from s(0..i) palindromic
       for(int i=0;i<n;i++){
         if(dp[0][i]==1) w[i]=0;
         else{
        for(int k=0;k<i;k++){
                if(dp[k+1][i]==1 && w[k]+1<w[i]){
                    w[i]=1+w[k];
                }
               
        }
         }
       }
       return w[n-1];
        
    }
};