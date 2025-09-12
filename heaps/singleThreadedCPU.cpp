#include<queue>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;
class Solution {
public:
    typedef pair<int,int> p;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<int> ans;
        //for every index we need to store its enqueue time,processing time and index
        vector<array<int,3>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(begin(jobs),end(jobs));
        //stores {processing time,index}
        priority_queue<p,vector<p>,greater<>> pq;
        int ind=0;
        long long currTime=0;
        while(ind<n || !pq.empty()){
            //if cpu is idle is currtime is less than the starting time of next process; cpu remains idle for this time and we jump to the starting time of next process
            if(pq.empty() && currTime<jobs[ind][0]) currTime=jobs[ind][0];
            while(ind<n && currTime>=jobs[ind][0]){
                pq.push({jobs[ind][1],jobs[ind][2]});
                ind++;
            }
            auto [process,idx]=pq.top();
            pq.pop();
            ans.push_back(idx);
            currTime+=process;
        }
        return ans;
    }
};