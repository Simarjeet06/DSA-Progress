#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        // Approach-1 (using khandani sliding window template)
        // int i=0,j=0;
        // map<int,int> freq;
        // int maxi=0;
        // while(j<n){
        //     freq[nums[j]]++;
        //     while(i<j && freq[nums[j]]>k){
        //         freq[nums[i]]--;
        //         i++;
        //     }
        //     maxi=max(maxi,j-i+1);
        //     j++;

        // }
        // return maxi;
        //Approach -2 (without nested loops)
        int i=0,j=0;
        int res=0;
        map<int,int> freq;
        int culprit=0;
        //we only increment i if there is a culprit and check if the freq of the current i element is equal to k if true we decrement culprit ;there if no culprit we compute max length 
        while(j<n){
           freq[nums[j]]++;
           if(freq[nums[j]]==k+1) culprit+=1;
           if(culprit>0){
            freq[nums[i]]--;
            //culprit discovered
            if(freq[nums[i]]==k) culprit-=1;
            i++;
           }
           if(culprit==0) res=max(res,j-i+1);
           j++;
        }
        return res;
    }
};