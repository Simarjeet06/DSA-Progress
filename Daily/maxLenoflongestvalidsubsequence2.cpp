#include <vector>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        // vector<int> dp(n,1);
        vector<vector<int>> dp(k,vector<int>(n,1));
        int maxi=1;
            for(int i=1;i<n;i++){
                for(int j=0;j<i;j++){
                   int mod=(nums[i]+nums[j])%k;
                   dp[mod][i]=max(dp[mod][i],1+dp[mod][j]);
                   maxi=max(maxi,dp[mod][i]);
                }
            }
        
        return maxi;
    }
};