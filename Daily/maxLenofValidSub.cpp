#include <vector>
using namespace std;
// class Solution {
// public:
//     int maximumLength(vector<int>& nums) {
//         int evenCnt=0;
//         int oddCnt=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i]%2==0) evenCnt++;
//             else oddCnt++;
//         }
//         int alternating=1;
//         int parity=nums[0]%2;
//         for(int i=1;i<n;i++){
//             int currParity=nums[i]%2;
//             if(parity!=currParity){
//                  alternating++;
//                  parity=currParity;
//             }
//             else continue;
//         }
//         return max({evenCnt,oddCnt,alternating});
//     }
// };
class Solution {
public:
    int LIS(vector<int>& nums,int curr,int prev,int mod,vector<vector<int>>& dp){
        if(curr==nums.size()) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int take=0;
        if(prev==-1 || ((nums[curr]+nums[prev])%2==mod)) {
            take=1+LIS(nums,curr+1,curr,mod,dp);
        }
        int skip=LIS(nums,curr+1,prev,mod,dp);
        return dp[curr][prev+1]=max(take,skip);
    }
    int maximumLength(vector<int>& nums) {
    //     int evenCnt=0;
    //     int oddCnt=0;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         if(nums[i]%2==0) evenCnt++;
    //         else oddCnt++;
    //     }
    //     int alternating=1;
    //     int parity=nums[0]%2;
    //     for(int i=1;i<n;i++){
    //         int currParity=nums[i]%2;
    //         if(parity!=currParity){
    //              alternating++;
    //              parity=currParity;
    //         }
    //         else continue;
    //     }
    //     return max({evenCnt,oddCnt,alternating});

    //Approach-2: Dp based
      int n=nums.size();
      int maxSubLength=1;
    //   vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //   maxSubLength=max(maxSubLength, LIS(nums,0,-1,0,dp));
    //   fill(dp.begin(),dp.end(),vector<int>(n+1,-1));
    //   maxSubLength=max(maxSubLength, LIS(nums,0,-1,1,dp));
    //   return maxSubLength;
    vector<int> dp(n,1);
    for(int k=0;k<=1;k++){
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if((nums[i]+nums[j])%2==k){
               dp[i]=max(dp[i],dp[j]+1);
                maxSubLength=max(maxSubLength,dp[i]);
            }
        }
    }
      fill(dp.begin(),dp.end(),1);
    }
  
    return maxSubLength;
    }
};