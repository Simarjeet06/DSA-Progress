class Solution {
public:
    int minOperations(vector<int>& nums) {
       int n=nums.size();
        // unordered_set<int> st(begin(nums),end(nums));
        // int ops=0;
        // for(int target:st){
        //     if(target==0) continue;
        //     bool flow=false;
        //     for(int i=0;i<n;i++){
        //          if(nums[i]==target){
        //             if(!flow){
        //                 ops++;
        //                //new subarray is counted sepaartely any insertions in this part will be calculated separately
        //                 flow=true;
        //             }
        //          }
        //          else if(nums[i]<target) flow=false;
        //     }
        // }
        // return ops;
        int ops=0;
        stack<int> st;
        for(int i=0;i<n;i++){
          while(!st.empty() && st.top()>nums[i]) st.pop();
          if(nums[i]==0) continue;
          if(st.empty() || st.top()<nums[i]){
            ops++;
            st.push(nums[i]);
          }
        }
        return ops;
    }
};