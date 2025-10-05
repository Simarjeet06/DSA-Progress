class Solution {
public:
    int m,n;
    int delRow[4]={-1,1,0,0};
    int delCol[4]={0,0,-1,1};
    void bfs(queue<pair<int,int>>& q,vector<vector<bool>>& vis,vector<vector<int>>& heights){
          while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+delRow[k];
                int ny=y+delCol[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && heights[nx][ny]>=heights[x][y] && !vis[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny]=true;
                }
            }
          }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pac(m,vector<bool>(n,false));
        vector<vector<bool>> atl(m,vector<bool>(n,false));
        queue<pair<int,int>> qp,qa;
        for(int i=0;i<m;i++){
            qp.push({i,0});
            pac[i][0]=true;
            qa.push({i,n-1});
            atl[i][n-1]=true;
        }
        for(int i=0;i<n;i++){
            qp.push({0,i});
            pac[0][i]=true;
            qa.push({m-1,i});
            atl[m-1][i]=true;
        }
        bfs(qp,pac,heights);
        bfs(qa,atl,heights);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};