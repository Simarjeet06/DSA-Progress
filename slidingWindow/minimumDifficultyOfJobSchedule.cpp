#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    int n;
    // int t[301][11];
    // int solve(int i,int d,vector<int>& jd){
    //     if(d==1){
    //        return  *max_element(jd.begin()+1,jd.end());
    //     }
    //     if(t[i][d]!=-1) return t[i][d];
    //    int maxD=jd[i];
    //    int finalResult=INT_MAX;
    //    for(int j=i;j<=n-d;j++){
    //     maxD=max(maxD,jd[j]);
    //     int res=maxD+solve(j+1,d-1,jd);
    //     finalResult=min(finalResult,res);
    //    }
    //    return t[i][d]=finalResult;
    // }
    int minDifficulty(vector<int>& jd, int d) {
        n=jd.size();
        if(n<d) return -1;
        // memset(t,-1,sizeof(t));
        // return solve(0,d,jd);
        vector<vector<int>> t(n+1,vector<int>(d+1,-1));
        //state defination:- t[i][j]->minimum difficulty in completing jobs starting from index i till index n-1 if i have d days;
         for(int i=0;i<n;i++){
            t[i][1]=*max_element(begin(jd)+i,end(jd));
         }
         for(int days=2;days<=d;days++){
            for(int i=0;i<=n-days;i++){
                int maxDifficulty=INT_MIN;
                int finalResult=INT_MAX;
                for(int j=i;j<=n-days;j++){
                     maxDifficulty=max(maxDifficulty,jd[j]);
                     int result=maxDifficulty+t[j+1][days-1];
                     finalResult=min(finalResult,result);
                }
                t[i][days]=finalResult;

            }
         }
      
       return t[0][d];  
    }
};