#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    // int t[303][303];
    // int solve(int l,int r,vector<int>& nums){
    //     if(r-l<2) return 0;
    //     if(t[l][r]!=-1) return t[l][r];
    //     int maxi=INT_MIN;
    //     //we try to find the last balloon to burst so that we have right and left elements respectively for subsequent partitions and hence independent partitions on the left and right;
    //     for(int coin=l+1;coin<r;coin++){
    //         int maxCoins=solve(l,coin,nums)+solve(coin,r,nums)+(nums[l]*nums[coin]*nums[r]);
    //         maxi=max(maxi,maxCoins);
    //     }
    //     return t[l][r]=maxi;

    // }
    int maxCoins(vector<int>& nums) {
        // memset(t,-1,sizeof(t));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> t(n,vector<int>(n,0));
        // return solve(0,n-1,nums);
        for(int len=2;len<n;len++){
            for(int i=0;i+len<n;i++){
                int j=i+len;
                t[i][j]=INT_MIN;
                for(int k=i+1;k<j;k++){
                    int coins=t[i][k]+t[k][j]+(nums[i]*nums[k]*nums[j]);
                    t[i][j]=max(t[i][j],coins);
                }
            }
        }
        return t[0][n-1];
    }
};