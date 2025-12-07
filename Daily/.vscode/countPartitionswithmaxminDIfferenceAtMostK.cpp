class Solution {
public:
    int n;
    int mod=1e9+7;
    vector<int> dp;
    int f(vector<int>& nums,int i,int k){
        if(i>=n) return 1;
        if(dp[i]!=-1 ) return dp[i];
        int mini=INT_MAX,maxi=INT_MIN;
        int ways=0;
        for(int j=i;j<n;j++){
            mini=min(mini,nums[j]);
            maxi=max(maxi,nums[j]);
            if(maxi-mini>k) break;
            ways=(ways+f(nums,j+1,k))%mod;
        }
        return dp[i]=ways;
    }
    int countPartitions(vector<int>& nums, int k) {
        n=nums.size();
        // dp.resize(n+1,0);
        // // return f(nums,0,k);
        // dp[n]=1;
        // for(int i=n-1;i>=0;i--){
        //     int ways=0;
        //     int mini=INT_MAX,maxi=INT_MIN;
        //     for(int j=i;j<n;j++){
        //      mini=min(mini,nums[j]);
        //      maxi=max(maxi,nums[j]);
        //      if(maxi-mini>k) break;
        //      ways=(ways+dp[j+1])%mod;
        //     }
        //     dp[i]=ways;
        // }
        // return dp[0];
        // number of ways of partitioning i+1 elements
        vector<long long> t(n+1,0);
        vector<long long> prefix(n+1,0);
        deque<int> maxDq,minDq;
        t[0]=1;
        prefix[0]=1;
        int i=0,j=0;
        while(j<n){
            while(!maxDq.empty() && nums[j]>nums[maxDq.back()]){
                maxDq.pop_back();
            }
            maxDq.push_back(j);
            while(!minDq.empty() && nums[j]<nums[minDq.back()]){
                minDq.pop_back();
            }
            minDq.push_back(j);
            while(i<=j && nums[maxDq.front()]-nums[minDq.front()]>k){
                i++;
                if(!maxDq.empty() && maxDq.front()<i) maxDq.pop_front();
                if(!minDq.empty() && minDq.front()<i) minDq.pop_front();
            }
            t[j+1]=((prefix[j]-(i>0?prefix[i-1]:0)+mod)%mod);
            prefix[j+1]=(prefix[j]+t[j+1])%mod;
            j++;
        }
        return (int)t[n];
    }
};