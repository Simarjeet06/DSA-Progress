#include<vector>
#include<deque>
using namespace std;    
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> dq;
        int ans=0;
        int n=nums.size();
        //monotonic decreasing
        deque<int> maxdq;
        //monotonic increasing
        deque<int> mindq;
        int i=0;
        for(int j=0;j<n;j++){
        //   while(!maxdq.empty() && maxdq.front()<i) maxdq.pop_front();
        //   while(!mindq.empty() && mindq.front()<i) mindq.pop_front();
          while(!maxdq.empty() && nums[maxdq.back()]<nums[j]) maxdq.pop_back();
          while(!mindq.empty() && nums[mindq.back()]>nums[j]) mindq.pop_back();
          maxdq.push_back(j);
          mindq.push_back(j);
          while(!maxdq.empty() && !mindq.empty() &&  nums[maxdq.front()]-nums[mindq.front()]>limit){
               i++;
            if(maxdq.front()<i) maxdq.pop_front();
           if( mindq.front()<i) mindq.pop_front();
        
          }
          ans=max(ans,j-i+1);
        }
        return ans;
    }
};
        
    