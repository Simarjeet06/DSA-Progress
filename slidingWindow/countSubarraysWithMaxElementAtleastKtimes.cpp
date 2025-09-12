#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int maxi=*max_element(nums.begin(),nums.end());
        // int freq=0;
        long long cnt=0;
        // while(i<=j && j<n){
        //     if(nums[j]==maxi) freq++;
        
        //     while(freq>=k){
        //           cnt+=(n-j);
        //           if(nums[i]==maxi) freq--;
        //           i++;
        //     }
        //      if(freq<k) j++;
        // }
        //interesting approach
       vector<long long> indices;
       for(int m=0;m<n;m++){
        if(nums[m]==maxi) indices.push_back(m);
        int st=indices.size();
        if(st>=k){
            int prevK=st-k;
            if(prevK>=0 && prevK<st){
            cnt+=(indices[prevK]+1);
            }
        }
       }
       
       return cnt;
    }
};