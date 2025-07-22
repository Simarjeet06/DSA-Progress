#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //Approach-1
       /* int n=nums.size();
        int l=0;
        int r=0;
        int sum=0;
        int maxSum=0;
        set<int> st;
        while( r<n){
            int el=nums[r];
            if(st.insert(el).second){
                st.insert(el);
                sum+=nums[r];
                maxSum=max(maxSum,sum);
                r++;
            }
            else{
                while(nums[l]!=el){
                   sum-=nums[l];
                   st.erase(nums[l]);
                   l++;
                }
                st.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
        }
        return maxSum;
        */
        //Approach-2 (slight improvement)
        int n=nums.size();
        vector<int> mpp(10001,-1);
        vector<int> cumSum(n,0);
        cumSum[0]=nums[0];
        for(int i=1;i<n;i++){
           cumSum[i]=cumSum[i-1]+nums[i];
        }
        int i=0;
        int j=0;
        int res=0;
        while(j<n){
            //jumping i for a valid window
            i=max(mpp[nums[j]]+1,i);
            int jthSum=cumSum[j];
            int ithSum=(i>0)?(cumSum[i-1]):0;
            res=max(res,jthSum-ithSum);
            mpp[nums[j]]=j;
            j++;
        }
        return res;
    }
};