#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int maxKpos=-1,minKpos=-1;
        int culpritPos=-1;
        long long ans=0;
        for(int i=0;i<n;i++){
            int el=nums[i];
            if(el>maxK || el<minK){
                culpritPos=i;
            }
            if(el==maxK){
             maxKpos=i;
            }
            if(el==minK){
                minKpos=i;
              
            }
             
            int temp=min(minKpos,maxKpos)-culpritPos;
            cout<<temp<<endl;
            ans+=(temp>0)?temp:0;
        }
        return ans;
        
    }
};