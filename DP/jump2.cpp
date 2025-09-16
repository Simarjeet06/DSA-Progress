#include<vector>
#include<algorithm>
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
class Solution {
public:
    int n;
    int t[10001];
    int solve(int i,vector<int>& nums){
        if(i==n-1) return 0;
        if(t[i]!=-1) return t[i];
        int mini=INT_MAX;
        for(int j=1;j<=nums[i] && j+i<n;j++){
            if(solve(i+j,nums)!=INT_MAX)
            mini=min(mini,1+solve(i+j,nums));
        }
        return t[i]=mini;
    }
    int jump(vector<int>& nums) {
        n=nums.size();
        // memset(t,-1,sizeof(t));
        // // return solve(0,nums);
        // //solve->min jumps starting from ith index to reach n-1th index
        // vector<int> dp(n,INT_MAX);
        // dp[n-1]=0;
        // for(int i=n-2;i>=0;i--){
        //     for(int j=1;j<=nums[i] && i+j<n;j++){
        //       if(dp[i+j]!=INT_MAX) dp[i]=min(dp[i],1+dp[i+j]);
        //     }
    
        // }
        // return dp[0];
        //greedy-based approach
        int jumps=0,farthest=0,end=0;
        for(int i=0;i<n-1;i++){
            farthest=max(farthest,nums[i]+i);
            if(i==end){
                jumps++;
                end=farthest;
            }
        }
        return jumps;

    }
};