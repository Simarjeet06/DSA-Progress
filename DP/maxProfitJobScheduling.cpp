#include<vector>
#include<algorithm>
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
class Solution {
public:
int n;
// int t[50001];
struct Job{
    int s,e,p;
    Job(int start,int end,int profit){
        s=start;
        e=end;
        p=profit;
    }
};
int search(int i,vector<Job>& jobs){
    int endTime=jobs[i].e;
    int s=i,e=n-1,next=n;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(jobs[mid].s>=jobs[i].e){
            next=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
     return next;
}
// int solve(int ind,vector<Job>& jobs){
//      if(ind>=n) return 0;
//      if(t[ind]!=-1) return t[ind];
//      int skip=solve(ind+1,jobs);
//      int nextjobInd=search(ind,jobs);
//      int take=jobs[ind].p+solve(nextjobInd,jobs);
//      return t[ind]=max(take,skip);
// }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=profit.size();
        vector<Job> jobs;
        for(int i=0;i<n;i++){
          Job j=Job(startTime[i],endTime[i],profit[i]);
          jobs.push_back(j);
        }
        sort(begin(jobs),end(jobs),[](const Job& a,const Job& b){
            return a.s<b.s;
        });
        // memset(t,-1,sizeof(t));
        // return solve(0,jobs);
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int skip=dp[i+1];
            int nextInd=lower_bound(jobs.begin()+i+1,jobs.end(),jobs[i].e,[](const Job& a,int val){
                return a.s<val;
        })-jobs.begin();
            dp[i]=max(dp[i+1],jobs[i].p+dp[nextInd]);
        }
        return dp[0];
    }
};