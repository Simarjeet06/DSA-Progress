
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[i]>arr[prev]){
                    if(dp[prev]+1>dp[i]){
                        dp[i]=dp[prev]+1;
                        hash[i]=prev;
                    }
                    
                }
            }
        }
        int maxi=0;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                ind=i;
            }
        }
        vector<int> ans;
        while(true){
             if(hash[ind]==ind) {
                ans.push_back(arr[ind]);
                break;
            }
            ans.push_back(arr[ind]);
            ind=hash[ind];
           
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};