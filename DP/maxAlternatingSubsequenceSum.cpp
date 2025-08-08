
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
   long long helper(vector<int>& nums,int i,int n,bool isEven,vector<vector<long long>>& dp){
    if(i==n) return 0;
    if(dp[i][isEven]!=-1) return dp[i][isEven];
    long long pick=(isEven==1)?nums[i]:-nums[i];
    pick+=helper(nums,i+1,n,!isEven,dp);
    long long  skip=helper(nums,i+1,n,isEven,dp);
    return dp[i][isEven]=max(pick,skip);
   }
    long long maxAlternatingSum(vector<int>& nums) {
        long long n=nums.size();
        // // vector<vector<long long>> dp(n,vector<long long>(2,0));
        // // return helper(nums,0,n,true,dp);
        // // dp[n-1][1]=nums[n-1];
        // long long even=0;
        // long long odd=0;
        // for(long long i=n-2;i>=-1;i--){
        //     // for(long long j=1;j>=0;j--){
        //         //    long long pick=(j==1)?nums[i]:-nums[i];
        //         //     pick+=dp[i+1][1-j];
        //         //     long long  skip=dp[i+1][j];
        //         //      dp[i][j]=max(pick,skip);
        //     // }
        //     long new_even=max(even,odd+nums[i+1]);
        //     long new_odd=max(odd,even-nums[i+1]);
        //     even=new_even;
        //     odd=new_odd;
        //     cout<<even<<" "<<odd<<endl;
        vector<vector<long>> dp(n+1,vector<long>(2,0));
        for(int i=1;i<n+1;i++){
            dp[i][0]=max(dp[i-1][1]-nums[i-1],dp[i-1][0]);
            dp[i][1]=max(dp[i][0]+nums[i-1],dp[i-1][1]);
        }
        
        return max(dp[n][0],dp[n][1]);
    }
    
};