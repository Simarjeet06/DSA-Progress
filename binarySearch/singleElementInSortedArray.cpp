class Solution {
public:
    int n;
    int binarySearch(vector<int>& nums,int l,int r){
       while(l<r){
        int mid=l+(r-l)/2;
        //we make mid even
        if(mid%2==1) mid--;
        if(nums[mid]==nums[mid+1]) l=mid+2;
        else r=mid;
       }
       return nums[l];
    }
    int singleNonDuplicate(vector<int>& nums) {
         n=nums.size();
        if(n==1) return nums[0];
        return binarySearch(nums,0,n-1);
    }
};