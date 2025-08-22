#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
  vector<int> nse,pse,nge,pge;
  void findpse(vector<int>& nums,int n){
    stack<int> st;
    for(int i=0;i<n;i++){
        //edge case
          while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
          pse[i]=st.empty()?-1:st.top();
          st.push(i);
    }
  }
   void findnse(vector<int>& nums,int n){
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        //edge case
          while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
          nse[i]=st.empty()?n:st.top();
          st.push(i);
    }
  }
   void findpge(vector<int>& nums,int n){
    stack<int> st;
    for(int i=0;i<n;i++){
        //edge case
          while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
          pge[i]=st.empty()?-1:st.top();
          st.push(i);
    }
  }
   void findnge(vector<int>& nums,int n){
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        //edge case
          while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
          nge[i]=st.empty()?n:st.top();
          st.push(i);
    }
  }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        nse.resize(n);
        pse.resize(n);
        nge.resize(n);
        pge.resize(n);
        findpse(nums,n);
        findnse(nums,n);
        findpge(nums,n);
        findnge(nums,n);
        long long sum=0;
        for(int i=0;i<n;i++){
            int el=nums[i];
            long long prevSmall=i-pse[i];
            long long prevGreater=i-pge[i];
            long long nextSmall=nse[i]-i;
            long long nextGreater=nge[i]-i;
            long long times=((nextGreater*prevGreater*1LL)-(nextSmall*prevSmall*1LL))*el;
            sum+=times;

        }
        return sum;
    }
};