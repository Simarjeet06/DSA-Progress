class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> temp(n+1,vector<int>(n+1,0));
        for(auto q:queries){
            int r1=q[0];
            int c1=q[1];
            int r2=q[2];
            int c2=q[3];
             temp[r1][c1]+=1;
            if(r2<n) temp[r2+1][c1]-=1;
            if(c2<n) temp[r1][c2+1]-=1;
            if(r2<n && c2<n) temp[r2+1][c2+1]+=1;
        }
        for(int i=0;i<=n;i++){
            for(int j=1;j<=n;j++){
              temp[i][j]+=temp[i][j-1];
            }
        }
        for(int j=0;j<=n;j++){
            for(int i=1;i<=n;i++){
              temp[i][j]+=temp[i-1][j];
            }
        }
        
       vector<vector<int>> ans(n,vector<int>(n,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]+=temp[i][j];
        }
       }
       return ans;
    }
};