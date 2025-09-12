#include<vector>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<int> t(n,0);
        if(n<3) return 0;
        int len=2;
        int diff=nums[1]-nums[0];
        // int ans=0;
        // for(int i=2;i<n;i++){
        //     if((nums[i]-nums[i-1])==diff){
        //         len++;
        //     }
        //     else{
        //         if(len>=3){
        //             int sz=len-2;
        //             ans+=(sz*(sz+1))/2;
        //         }
        //         len=2;
        //         diff=nums[i]-nums[i-1];
        //     }
        // }
        // int cnt=len-2;
        //  ans+=(cnt*(cnt+1))/2;
        //  return ans;
        int total=0;
        int curr=0;
        for(int i=2;i<n;i++){
            if((nums[i]-nums[i-1]) == (nums[i-1]-nums[i-2])){
                curr+=1;
                total+=curr;
            }
            else curr=0;
    }
    return total;
    }
};