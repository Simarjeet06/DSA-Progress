class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> lis(n,1);
        vector<int> cnt(n,1);
        int maxi=1,sum=0;
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev] && lis[prev]+1>lis[i]){
                    lis[i]=1+lis[prev];
                    cnt[i]=cnt[prev];
                    maxi=max(maxi,lis[i]);
                }
                else if(nums[i]>nums[prev] && lis[prev]+1==lis[i]) cnt[i]+=cnt[prev];
            }
        }
        for(int i=0;i<n;i++){
          if(lis[i]==maxi) sum+=cnt[i];
        }
        
       return sum;
    }
};