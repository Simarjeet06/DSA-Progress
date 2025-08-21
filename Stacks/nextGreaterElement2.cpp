#include<vector>
#include<stack>
using namespace std;
class Solution {
public:

    vector<int> nextGreaterElements(vector<int>& nums) {
        //approach-1
        int n=nums.size();
    //     vector<int> ans(n,-1);
    //   for(int i=0;i<n;i++){
    //      int ind=(i+1)%n;
    //      while(ind!=i && nums[ind]<=nums[i]){
    //         ind=(ind+1)%n;
    //      }
    //      if(ind==i) ans[i]=-1;
    //      else ans[i]=nums[ind];
    //   }
    //   return ans;
    //approach-2
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=2*n-1;i>=0;i--){
      // We loop 2*n times so that each element can "see" all elements after it in circular order.
// We only fill ans[i] during the first pass (i < n) to avoid duplicate updates.

        int num=nums[i%n];
        while(!st.empty() && nums[st.top()]<=num){
            st.pop();
        }
        if(i<n){
            ans[i]=(st.empty())?-1:nums[st.top()];
        }
        st.push(i%n);
    }
    return ans;
    }
};