#include<vector>
#include<string>
using namespace std;
class Solution {
public:
 vector<vector<string>> ans;
 vector<string> temp;
   void backtrack(vector<vector<int>>& dp,int start,string s,int n){
      if(start>=n){
       ans.push_back(temp);
       return;
      }
       for(int e=start;e<n;e++){
        if(dp[start][e]==1){
            temp.push_back(s.substr(start,e-start+1));
            backtrack(dp,e+1,s,n);
            temp.pop_back();
        }
       }
   }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if(j==i+1 && s[i]==s[j]) dp[i][j]=1;
                else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
            }
        }
        backtrack(dp,0,s,n);
        return ans;
       
    }
};