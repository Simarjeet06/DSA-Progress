#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
 int N,M,K;
 int dp[51][51][102];
 int mod=1e9+7;
    int solve(int idx,int searchCost,int maxSofar){
        //base case -> out of bounds
        if(idx==N){
            if(searchCost==K) return 1;
            return 0;
        }
        if(dp[idx][searchCost][maxSofar+1]!=-1) return dp[idx][searchCost][maxSofar+1];
        long long result=0;
        for(int i=1;i<=M;i++){
            if(i>maxSofar)
             result=(result+(solve(idx+1,searchCost+1,i)%mod))%mod;
            else {
                result=(result+(solve(idx+1,searchCost,maxSofar)%mod))%mod;
            }
        }
        return dp[idx][searchCost][maxSofar+1]=result;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,-1);
    }
};