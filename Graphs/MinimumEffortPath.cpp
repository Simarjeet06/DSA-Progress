#include<vector>
#include<queue>
#include<climits>
#include<cmath>
using namespace std;    
class Solution {
public:
    int delRow[4]={0,-1,0,1};
     int delCol[4]={-1,0,1,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int dt=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int newx=x+delRow[i];
                int newy=y+delCol[i];
                if(newx>=0 && newx<m && newy>=0 && newy<n){
                    int diff=abs(heights[newx][newy]-heights[x][y]);
                    int maxEffort=max(diff,dt);
                    if(dist[newx][newy]>maxEffort){
                        dist[newx][newy]=maxEffort;
                        pq.push({maxEffort,{newx,newy}});
                    }
                }
            }
        }
        return dist[m-1][n-1];

    }
};