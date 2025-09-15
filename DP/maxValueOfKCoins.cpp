#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
int n;
vector<vector<int>> prefix;
vector<vector<int>> t;
    // int solve(int i,int k){
    //     if(i>=n || k==0) return 0;
    //     if(t[i][k]!=-1) return t[i][k];
    //     int take=0,skip=0;
    //      skip=solve(i+1,k);
    //     for(int x=1;x<=min((int)prefix[i].size(),k);x++){
    //         take=max(take,prefix[i][x-1]+solve(i+1,k-x));
    //     }
    //     return t[i][k]=max(take,skip);
    // }
    int solve(int i,int k,vector<vector<int>>& piles){
        if(i>=n) return 0;
        int skip=solve(i+1,k,piles);
        int sum=0,take=0;
        for(int j=0;j<min((int)piles[i].size(),k);j++){
           sum+=piles[i][j];
           take=max(take,sum+solve(i+1,k-(j+1),piles));
        }
        return max(take,skip);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        int maxi=0;
        for(int i=0;i<n;i++)  maxi=max(maxi,(int)piles[i].size());
        prefix.resize(n);
        for(int i=0;i<n;i++){
            prefix[i].resize(piles[i].size());
            prefix[i][0]=piles[i][0];
            for(int j=1;j<prefix[i].size();j++){
                prefix[i][j]=prefix[i][j-1]+piles[i][j];
            }
        }
        t.resize(n+1,vector<int>(k+1,0));
        // return solve(0,k,piles);
        //state defination t[i][j]->max coins if i have i piles and j coins
        for(int i=1;i<=n;i++){
            for(int coins=1;coins<=k;coins++){
                //skip
                t[i][coins]=t[i-1][coins];
               for(int currcoins=1;currcoins<=min((int)prefix[i-1].size(),coins);currcoins++){ 
                t[i][coins]=max(t[i][coins],prefix[i-1][currcoins-1]+t[i-1][coins-currcoins]);
               }
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                cout<<t[i][j]<<" ";
            }
            cout<<endl;
        }
        return t[n][k];
    }
};