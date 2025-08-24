#include<vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        int cntZeros=0;
        int maxi=0;
        //since we need to delete one element we want a window of max 1's such that it can contain 1 0 so we try to find the size of window that has 1 zero and max size and if we don not have a zero w delete a one 
        for(int right=0;right<n;right++){
           if(nums[right]==0)cntZeros++;
           while(cntZeros>1 && left<=right){
               if(nums[left]==0) cntZeros--;
               left++;
           }
           maxi=max(maxi,right-left);
        }
        return maxi;
    }
};