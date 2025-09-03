#include<vector>
using namespace std;    
class Solution {
public:
int n;
int t[366];
    int solve(vector<int>& days,vector<int>& costs,int i){
        if(i>=n) return 0;
        if(t[i]!=-1) return t[i];
        int path1=costs[0]+solve(days,costs,i+1);
        int j=i;
        int maxday=days[i]+7;
        while(j<n && days[j]<maxday){
            j++;
        }
        int path2=costs[1]+solve(days,costs,j);
        int k=i;
        maxday=days[i]+30;
        while(k<n && days[k]<maxday) k++;
        int path3=costs[2]+solve(days,costs,k);
        return t[i]=min({path1,path2,path3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         n=days.size();
        //  memset(t,-1,sizeof(t));
        // return solve(days,costs,0);
        vector<int> dp(n,0);
        //state defn:- dp[i]->minimum number of dollars to travel ith  to nth day
        dp[n-1]=min({costs[0],costs[1],costs[2]});
        for(int i=n-2;i>=0;i--){
            int path1=costs[0]+dp[i+1];
            int j=i;
            while(j<n && days[j]<days[i]+7) j++;
            int path2=costs[1]+((j<n)?dp[j]:0);
            int k=i;
            while(k<n && days[k]<days[i]+30) k++;
            int path3=costs[2]+(k<n?dp[k]:0);
            dp[i]=min({path1,path2,path3});
        }
        return dp[0];
    }
};