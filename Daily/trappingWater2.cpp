class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<p,vector<p>,greater<p>> pq;
        int m=heightMap.size();
        int n=heightMap[0].size();
        int delRow[4]={-1,1,0,0};
        int delCol[4]={0,0,-1,1};
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            pq.push({heightMap[i][0],{i,0}});
            pq.push({heightMap[i][n-1],{i,n-1}});
            vis[i][0]=true;
            vis[i][n-1]=true;
        }
        for(int i=1;i<n-1;i++){
            pq.push({heightMap[0][i],{0,i}});
            pq.push({heightMap[m-1][i],{m-1,i}});
            vis[0][i]=true;
            vis[m-1][i]=true;
        }
        int trappedWater=0;
        while(!pq.empty()){
           auto [height,coordinates]=pq.top();
           pq.pop();
           int i=coordinates.first;
           int j=coordinates.second;
           for(int k=0;k<4;k++){
            int nx=i+delRow[k];
            int ny=j+delCol[k];
            if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                trappedWater+=max((heightMap[i][j]-heightMap[nx][ny]),0);
                heightMap[nx][ny]=max(heightMap[nx][ny],heightMap[i][j]);
                pq.push({heightMap[nx][ny],{nx,ny}});
                vis[nx][ny]=true;
            }
           } }
                   return trappedWater;
    }
};