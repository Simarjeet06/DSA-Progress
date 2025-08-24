#include<string>
#include<vector>
using namespace std;
class Solution {
public:
int t[1001][1001];
bool isPalindrome(string s,int i,int j){
    if(i>j) return true;
    if(t[i][j]!=-1) return t[i][j];
    else if(s[i]!=s[j]) return t[i][j]=false;
    return t[i][j]=isPalindrome(s,i+1,j-1);
}
    int helper(string s,int n){
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                   cnt+=isPalindrome(s,i,j);
                  }
            }
        
return cnt;
    }
    int countSubstrings(string s) {
        int n=s.size();
        memset(t,0,sizeof(t));
        vector<vector<int>> dp(n,vector<int>(n,0));
        // return helper(s,n);
        //state defination-> t[i][j] tells us if the string from ith to jth character is a palindrome or not
        int cnt=0;
        // for(int i=0;i<n;i++){
        //   dp[i][i]=1;
        //     cnt+=dp[i][i];
        // }
        // for(int i=n-2;i>=0;i--){
        //     for(int j=i+1;j<n;j++){
        //         if(s[i]==s[j]){
        //             if(j==i+1 || dp[i+1][j-1]){
        //                 dp[i][j]=1;
        //             }
        //         }
        //         cnt+=dp[i][j];
        //     }
        // }
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(i==j) dp[i][j]=1;
                else if(j==i+1) dp[i][j]=(s[i]==s[j]);
                else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
                 if(dp[i][j]) cnt++;
            }
           
        }
        
        return cnt;
    }
};