#include<vector>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // vector<int> clean;
        // for(int i=0;i<nums.size();i++){
        //     if(i==0 || (nums[i]!=nums[i-1])) clean.push_back(nums[i]);
        // }
        int cnt=0;
        int n=nums.size();
        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i-1]) continue;
            int left=nums[i]-nums[i-1];
            int ind=i+1;
            while(ind<n && nums[i]==nums[ind] ){
                ind++;
            }
             if(ind<n){
             int right=nums[i]-nums[ind];
             long long num=left*right;
            if(num>0)
                cnt++;
             }
        }
        return cnt;
    }
};