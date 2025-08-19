#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
     unordered_map<string,long long> mpp;
    long long solve(int prev,int idx,vector<int>& nums){
        if(idx>=nums.size()) return 0;
        long long taken=INT_MIN;
        long long skip=INT_MIN;
        string key=to_string(prev)+"_"+to_string(idx);
        if(mpp.find(key)!=mpp.end()) return mpp[key];
        if(prev==-1 || (nums[idx]-idx)>=(nums[prev]-prev)){
            taken=nums[idx]+solve(idx,idx+1,nums);
        }
        skip=solve(prev,idx+1,nums);
         return mpp[key]=max<long long>(taken,skip);
        
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int maxEl=*max_element(begin(nums),end(nums));
        if(maxEl<=0) return maxEl;
        // return solve(-1,0,nums);
        int n=nums.size();
        // long long maxSum=nums[0];
        // vector<long long> t(n);
        // for(int i=0;i<n;i++){
        //     t[i]=nums[i];
        // }
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]-i >= nums[j]-j){
        //             t[i]=max(nums[i]+t[j],t[i]);
        //             maxSum=max(maxSum,t[i]);
        //         }
        //         else continue;
        //     }
        // }
        // return maxSum;
        map<int,long long> mpp;
        long long res=INT_MIN;
        for(int i=0;i<n;i++){
           auto it= mpp.upper_bound(nums[i]-i);
           long long sum=nums[i];
           if(it!=mpp.begin()){
            it--;
            sum+=it->second;
           }
           mpp[nums[i]-i]=max(sum,mpp[nums[i]-i]);
           res=max(res,mpp[nums[i]-i]);
           it=mpp.upper_bound(nums[i]-i);
           while(it!=mpp.end() && it->second<=mpp[nums[i]-i]){
            mpp.erase(it++);
           }
        }
        return res;
    }
};