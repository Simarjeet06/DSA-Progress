#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
class Solution {
public:
int m,n;
vector<vector<int>> dp;
int t[501][501];
    int solve(string& word1,string& word2,int i,int j){
            if(i==m ) return n-j; //additions
            if(j==n) return m-i;//deletions
            if(dp[i][j]!=-1) return dp[i][j];
            int insertop=0,deleteop=0,replaceop=0;
            if(word1[i]==word2[j]) return dp[i][j]=solve(word1,word2,i+1,j+1);
            else{
                insertop=solve(word1,word2,i,j+1);
                deleteop=solve(word1,word2,i+1,j);
                replaceop=solve(word1,word2,i+1,j+1);

            }
            return dp[i][j]=1+min({insertop,deleteop,replaceop});
    }
    int solve2(string& s1,string& s2,int m,int n){
        if(m==0||n==0){
            //if the first string is empty then we need to add or insert the remaining characters of string2; similarly if string 2 is empty the remaining m characters of first string need to be deleted.
            return m+n;
        }
        if(t[m][n]!=-1) return t[m][n];
        int insertC=0,deleteC=0,replaceC=0;
        //since both characters have matched we move both the pointers;
         if(s1[m-1]==s2[n-1]) return t[m][n]=solve2(s1,s2,m-1,n-1);
         
        else{
            // we matched the nth character of s2 so we move that we keep mth character since that can be matched in future
              insertC=1+solve2(s1,s2,m,n-1);
              //we have deleted the mth character of string1 but we haven't matched nth character yet so it needs to be kept;
              deleteC=1+solve2(s1,s2,m-1,n);
              //since we have matched both the characters we move both m and n pointers
              replaceC=1+solve2(s1,s2,m-1,n-1);
              
        }
        return t[m][n]=min({insertC,deleteC,replaceC});
    }
    int minDistance(string word1, string word2) {
         m=word1.size();
         n=word2.size();
         dp.resize(m+1,vector<int>(n+1,0));
        //  return solve(word1,word2,0,0);

        memset(t,-1,sizeof(t));
        return solve2(word1,word2,m,n);
        //state defn:- dp[i][j]->min. number of operations required to convert string 1  of length i to string 2 of length j
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
               if(i==0 || j==0) dp[i][j]=i+j;
                else{
                    if(word1[i-1]==word2[j-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    }
                }

            }
        }
        // return dp[m][n];
    }
};