#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    vector<vector<int>> t;
    // int solve(int l,int r,vector<int>& cuts){
    //  if(r-l<2) return 0;
    //  if(t[l][r]!=-1) return t[l][r];
    //  int mini=INT_MAX;
    //  for(int cut=l+1;cut<r;cut++){
    //     int cost=solve(l,cut,cuts)+solve(cut,r,cuts)+(cuts[r]-cuts[l]);
    //     mini=min(mini,cost);
    //  }
    //  return t[l][r]=mini;
    // }
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts),end(cuts));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        int num=cuts.size();
        int l=0;
        t.resize(num,vector<int>(num,0));
        // return solve(0.                                    ,num-1,cuts);
        for(int len=2;len<num;len++){
            for(int i=0;i<=num-len-1;i++){
               int j=i+len;
               t[i][j]=INT_MAX;
               for(int k=i+1;k<j;k++){
                int cost=t[i][k]+t[k][j]+(cuts[j]-cuts[i]);
                t[i][j]=min(cost,t[i][j]);
               }
            }
        }
        return t[0][num-1];

    }
};