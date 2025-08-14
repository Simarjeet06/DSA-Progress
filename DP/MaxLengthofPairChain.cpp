#include <vector>
#include <algorithm>        
using namespace std;
class Solution {
public:
    int dp[1000][1001];
    int solve(vector<vector<int>>& pairs,int ind,int n,int lastVal){
        if(ind==n) return 0;
        if(lastVal!=-1 && dp[ind][lastVal]!=-1) return dp[ind][lastVal];
        int take=0;
        if(lastVal==-1 || pairs[ind][0]>pairs[lastVal][1]){
            take=1+solve(pairs,ind+1,n,ind);
        }
        int skip=solve(pairs,ind+1,n,lastVal);
        if(lastVal!=-1) dp[ind][lastVal]=max(skip,take);
        return max(skip,take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end());
        // return solve(pairs,0,n,-1);
        vector<int> t(n,1);
        int longestChain=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    t[i]=max(t[i],t[j]+1);
                    longestChain=max(longestChain,t[i]);
                }
            }
        }
        return longestChain;
    }
};