#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //  int dp[101];
    // int f(vector<int>& nums,int i,int n){
    //     if(i>n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int take=nums[i]+f(nums,i+2,n);
    //     int skip=f(nums,i+1,n);
    //     return dp[i]=max(take,skip);
    // }
    // int func(vector<int>& nums,int ind,int n){
    //      for(int i=ind;i<=n;i++){
    //         dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
    //      }
    //      return dp[n];
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]); 
        // int take_0thindex=f(nums,0,n-2);
        // memset(dp,-1,sizeof(dp));
        // int take_1stindex=f(nums,1,n-1);
        // return max(take_0thindex,take_1stindex);
         vector<int> dp(n+1,0);
        dp[0]=0;
        //when robbing the 1st house
        for(int i=1;i<=n-1;i++){
            dp[i]=max(dp[i-1],nums[i-1]+((i>=2)?dp[i-2]:0));
        }
        int el1=dp[n-1];
        dp.resize(n+1,0);
        //when not robbing the first house , the last house can be robbed
        dp[0]=0;
        dp[1]=0;
         for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-1],nums[i-1]+((i>=2)?dp[i-2]:0));
        }
        int el2=dp[n];
        return max(el1,el2);

    }
};