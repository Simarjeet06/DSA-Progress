#include <vector>
#include <algorithm>
#include <iostream> 
using namespace std;
class Solution {
public:
    // vector<int> best;
    // int dp[1001][1001];
    // void solve(vector<int>& nums,vector<int>& curr,int i,int n,int prev){
    //     if(i>=n){
    //        if(curr.size()>best.size()){
    //         best=curr;
            
    //        }
    //        return;
    //     }
    //     // if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    //     if(prev==-1 || ((nums[i]>nums[prev]) && (nums[i]%nums[prev]==0))){
    //         curr.push_back(nums[i]);
    //         solve(nums,curr,i+1,n,i);
    //         curr.pop_back();
    //     }
    //     solve(nums,curr,i+1,n,prev);

    // }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        // memset(dp,-1,sizeof(dp));
        vector<int> curr;
        //  solve(nums,curr,0,n,-1);
        //  return best;
        int maxi=0,curi=1;
        vector<int> temp(n,1),t(n);
        vector<int> ans;
        for(int i=0;i<n;i++) t[i]=i;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && temp[j]+1>temp[i]){
                    temp[i]=temp[j]+1;
                    t[i]=j;
                    if(temp[i]>curi){
                        curi=temp[i];
                        maxi=i;
                    }
                    
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<temp[i]<<" "<<t[i]<<endl;
        }
        for(int i=0;i<curi;i++){
            int el=nums[maxi];
        ans.push_back(nums[maxi]);
        maxi=t[maxi];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};