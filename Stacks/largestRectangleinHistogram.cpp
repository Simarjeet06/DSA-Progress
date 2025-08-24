#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> pse,nse;
    void findpse(vector<int>& heights,int n){
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            pse[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        
    }
    void findnse(vector<int>& heights,int n){
          stack<int> st;
          for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            nse[i]=(st.empty())?n:st.top();
            st.push(i);
          }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        pse.resize(n);
        nse.resize(n);
        findpse(heights,n);
        findnse(heights,n);
        int maxi=0;
        for(int i=0;i<n;i++){
            int limits=nse[i]-pse[i]-1;
            maxi=max(maxi,heights[i]*limits);
        }
        return maxi;
    }
};