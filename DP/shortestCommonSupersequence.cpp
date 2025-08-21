#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //dp[i][j]->length of SCS for s1 of length i and s2 of length j
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0) dp[i][j]=i+j;
                else if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        string s;
        int ind1=m;
        int ind2=n;
        while(ind1>0 &&  ind2>0){
            if(str1[ind1-1]==str2[ind2-1]){
                s.push_back(str1[ind1-1]);
                ind1--;
                ind2--;
            }
            else{
                if(dp[ind1-1][ind2]<dp[ind1][ind2-1]){
                    s.push_back(str1[ind1-1]);
                      ind1--;
                }
                else{
                     s.push_back(str2[ind2-1]);
                     ind2--;
                }
            }
        }
        while(ind1>0) {
            s.push_back(str1[ind1-1]);
            ind1--;
        }
         while(ind2>0) {
            s.push_back(str2[ind2-1]);
            ind2--;
        }

        reverse(s.begin(),s.end());
        return s;
    }
};