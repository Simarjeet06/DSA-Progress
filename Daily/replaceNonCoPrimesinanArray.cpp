#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<iostream>
using namespace std;
class Solution {
public:
    int findGcd(int a,int b){
        return (b==0)?a:findGcd(b,a%b);
    }
    int findLCM(int a,int b){
        int gcdMain=findGcd(a,b);
        return ((1LL*a/gcdMain)*b);

    }
    int LCM2(int a ,int b){
        int maxi=max(a,b);
        int mini=min(a,b);
        int ans=0;
        for(int i=maxi;i<=(a*b);i+=maxi){
            if(i%mini==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();
        int j=1;
        stack<int> st;
        st.push(nums[0]);
        for(j=1;j<n;j++){
           int curr=nums[j];
          
           while(!st.empty() && findGcd(st.top(),curr)>1){
             int top=st.top();
            st.pop();
            curr=findLCM(curr,top);
           }
           st.push(curr);
        }

        vector<int> ans(st.size());
          for(int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
          }
        
        return ans;
    }
};