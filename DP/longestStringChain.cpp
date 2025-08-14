#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:  
bool checkPredecessor(string newWord,string prev){
    //checking if prev is a subsequence of newWord
    int n=prev.size();
    int m=newWord.size();
    int i=0,j=0;
    if(n>=m || m-n!=1) return false;
    while(i<n && j<m){
        if(prev[i]==newWord[j]) i++;
        j++;
    }
    return (i==n);
}

    int solve(vector<string>& words,int i,int prev,int n,vector<vector<int>>& dp){
          if(i==n) return 0;
          if(dp[i][prev+1]!=-1) return dp[i][prev+1];
          int take=0;
          if(prev==-1 || checkPredecessor(words[i],words[prev])){
            take=1+solve(words,i+1,i,n,dp);
          }
            int skip=solve(words,i+1,prev,n,dp);
            return dp[i][prev+1]=max(take,skip);
          
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string& a,const string& b){
            return a.length()<b.length();
        });
        int n=words.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        vector<int> dp(n,1);
    //    return solve(words,0,-1,n,dp);
    int maxi=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
        if(checkPredecessor(words[i],words[j])){
            dp[i]=max(dp[i],dp[j]+1);
            maxi=max(maxi,dp[i]);
        }
    }
    }
    return maxi;
    }
};