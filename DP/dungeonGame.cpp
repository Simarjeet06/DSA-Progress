#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<climits>
using namespace std;
class Solution {
public:
int m,n;
int dp[201][201];
unordered_map<string,bool> mpp;
    bool canSurvive(vector<vector<int>>& mat,int i ,int j,int mid){
        if(i>=m || j>=n) return false;
        mid+=mat[i][j];
        if(mid<=0) return false;
        else if(i==m-1 && j==n-1) return true;
        string key=to_string(i)+" "+to_string(j)+" "+to_string(mid);
        if(mpp.count(key)) return mpp[key];
        return mpp[key]=canSurvive(mat,i+1,j,mid)||canSurvive(mat,i,j+1,mid);
    }
    int solve(vector<vector<int>>& dungeon,int i,int j){
        if(i>=m || j>=n) return 1e9;
          if(dp[i][j]!=-1) return dp[i][j];
        //if i reach the last cell which has a positive value then a min of 1 health point at its arrival will do however if it has negative points then i need abs(mat[m-1][n-1])+1 to survive;
        else if(i==m-1 && j==n-1) return dp[i][j]=(dungeon[i][j]<0)?(abs(dungeon[i][j])+1):1;
      
        int down=solve(dungeon,i+1,j);
        int right=solve(dungeon,i,j+1);
        int val=min(down,right)-dungeon[i][j];
        //if val is negative then current value is greater than what is required at next so coming with a health point of 1 will do otherwise i need val health points;
        return dp[i][j]=(val<=0)?1:val;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        int l=1;
    //considering max health to be 200*200*1000
        int r=4*1e7;
        int maxHealth=0;
        //brute force->checking all possible healths and computing minimum using binary search
        // while(l<=r){
        //     mpp.clear();
        //     int mid=l+((r-l)/2);
        //     if(canSurvive(dungeon,0,0,mid)){
        //         maxHealth=mid;
        //         r=mid-1;
        //     }
        //     else l=mid+1;

        // }
        // return maxHealth;
        memset(dp,0,sizeof(dp));
        //state defn:- min health points to reach (m-1,n-1) from (i,j)
        // return solve(dungeon,0,0);
        dp[m-1][n-1]=(dungeon[m-1][n-1]>=0)?1:abs(dungeon[m-1][n-1])+1;
        for(int i=m-2;i>=0;i--){
            int val=dp[i+1][n-1]-dungeon[i][n-1];
         dp[i][n-1]=(val>0)?val:1;
        }
        for(int j=n-2;j>=0;j--){
        int val=dp[m-1][j+1]-dungeon[m-1][j];
         dp[m-1][j]=(val>0)?val:1;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                int down=(i+1<m)?dp[i+1][j]:INT_MAX;
                int right=(j+1<n)?dp[i][j+1]:INT_MAX;
                int val=min(down,right)-dungeon[i][j];
                dp[i][j]=(val>0)?val:1;
            }
        }
        return dp[0][0];
    }
};