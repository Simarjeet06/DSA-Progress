#include<vector>
using namespace std;
class Solution {
public:
    int dp[102][102];
    bool solve(string& s1,string& s2,string& s3,int i,int j){
        int k=i+j;
        if(i==s1.size() && j==s2.size() && k==s3.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool a=((i<s1.size()) && (s1[i]==s3[k]) && solve(s1,s2,s3,i+1,j));
        bool b=((j<s2.size()) && (s2[j]==s3[k]) && solve(s1,s2,s3,i,j+1));
        return dp[i][j]=a||b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        // memset(dp,0,sizeof(dp));
        // return solve(s1,s2,s3,0,0);
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>> t(m+1,vector<int>(n+1,0));
  //state defination:- t[i][j]->tells me whether s3(0..i+j-1) is an interleaving of s1(0..i-1) and s2(0..j-1)
    t[0][0]=1;
    for(int i=1;i<=m;i++){
          t[i][0]=((s1[i-1]==s3[i-1]) &&(t[i-1][0]));

    }
    for(int j=1;j<=n;j++){
        t[0][j]=(s2[j-1]==s3[j-1]) &&(t[0][j-1]);
    }
      for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int left=(t[i][j-1] && s2[j-1]==s3[i+j-1]);
            int  top=(t[i-1][j] && s1[i-1]==s3[i+j-1]);
            t[i][j]=left||top;
        }
      }
     
      return t[m][n];
    }
};