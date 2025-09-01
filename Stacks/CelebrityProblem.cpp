#include<vector>
#include<stack>
using namespace std;
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        //approach-1:using indegree approach
        int n=mat.size();
        // vector<int> indegree(n,1),outdegree(n,1);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==j) continue;
        //         if(mat[i][j]==1){
        //             outdegree[i]++;
        //             indegree[j]++;
        //         }
        //     }
        // }
        // int celebrity=-1;
        // for(int i=0;i<n;i++){
        //     if(indegree[i]==n && outdegree[i]==1) celebrity=i;
        // }
        // return celebrity;
        
        //approach2 :using stacks
        // stack<int> st;
        // for(int i=0;i<n;i++) st.push(i);
        // while(st.size()>1){
        //     int a=st.top();
        //     st.pop();
        //     int b=st.top();
        //     st.pop();
        //     if(mat[a][b]) st.push(b);
        //     else st.push(a);
        // }
        // int potentialCelebrity=st.top();
        // st.pop();
        // for(int i=0;i<n;i++){
        //     if(i==potentialCelebrity) continue;
        //     if(mat[potentialCelebrity][i] || !mat[i][potentialCelebrity])
        //     return -1;
        // }
        // return potentialCelebrity;
        
        //approach-3: using 2 pointers
        int i=0;
        int j=n-1;
        while(i<j){
            if(mat[i][j]) i++;
            else j--;
            
        }
        int celebrity=i;
        for(int j=0;j<n;j++){
            if(j==celebrity) continue;
            if(mat[celebrity][j] || !mat[j][celebrity]) return -1;
        }
        return celebrity;
    }
};