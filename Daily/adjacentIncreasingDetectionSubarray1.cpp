class Solution {
public:
    int n;
    bool isIncreasing(vector<int>& nums,int startIndex,int k){
        // if(n-startIndex<k+1) return false;
          while(k-- && startIndex+1<n){
            if(nums[startIndex]<nums[startIndex+1]) startIndex++;
            else return false;
          }
          return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        n=nums.size();
        for(int i=0;i+2*k<=n;i++){
            if(isIncreasing(nums,i,k-1) && isIncreasing(nums,i+k,k-1)) return true;
        }
        return false;
    }
};