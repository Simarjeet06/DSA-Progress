class Solution {
public:
    // typedef pair<int,pair<int,int>> p;
    int delRow[4]={-1,1,0,0};
    int delCol[4]={0,0,-1,1};
    int n;
    // //{time,{x,y}}
    // priority_queue<p,vector<p>,greater<>> pq;
    bool isPossible(vector<vector<int>>& grid,int time){
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        if(grid[0][0]<=time) q.push({0,0});
        vis[0][0]=true;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            if(x==n-1 && y==n-1) return true;
            for(int k=0;k<4;k++){
                int nx=x+delRow[k];
                int ny=y+delCol[k];
                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny]<=time){
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                    
                }
            }
        }
        return false;
    }
    int binary(int l,int r,vector<vector<int>>& grid){
        int result=-1;
        while(l<=r){
            int mid=l+((r-l)/2);
            //i can reach the (n-1,n-1) cell within this time but i will try to further minimise this 
            if(isPossible(grid,mid)){
                result=mid;
                r=mid-1;
            }
            // i need some more time to reach (n-1,n-1)
            else l=mid+1;
        }
        return result;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        return binary(0,n*n-1,grid);
        // vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        // dist[0][0]=grid[0][0];
        // pq.push({grid[0][0],{0,0}});
        // while(!pq.empty()){
        //      auto [time,cell]=pq.top();
        //      pq.pop();
        //      int x=cell.first;
        //      int y=cell.second;
        //      if(x==n-1 && y==n-1) return time;
        //      for(int k=0;k<4;k++){
        //         int nx=x+delRow[k];
        //         int ny=y+delCol[k];;
        //         if(nx>=0 && nx<n && ny>=0 && ny<n){
        //             int newTime=max(time,grid[nx][ny]);
        //             if(dist[nx][ny]>newTime){
        //                dist[nx][ny]=newTime;
        //                pq.push({newTime,{nx,ny}});
        //             }
        //         }
        //      }
        // }
        // return -1;
    }
};