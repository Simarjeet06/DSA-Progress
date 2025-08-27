#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int j=0;j<n;j++){
            //this will tell me the valid index to delete element.
            while(!dq.empty() && dq.front()<=j-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[j]) dq.pop_back();
          
         dq.push_back(j);
        if(j>=k-1){
            ans.push_back(nums[dq.front()]);
        }
        }
        
        return ans;
    }
};