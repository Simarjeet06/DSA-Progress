#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        // vector<int> ans;
        //  for(int j=0;j<=n;j++){
        //     int cnt=0;
        //    for(int i=0;i<=31;i++){
        //     int temp=(1<<i);
        //     if((temp & j)!=0) cnt++;   
        // }
        // ans.push_back(cnt);
        //  }
        //  return ans;
        //appraoch -2 : observation based every even number has same counts as its half's count while every odd number has count. of its half plus 1 
        vector<int> result(n+1,0);
        for(int i=1;i<=n;i++){
             result[i]=(i & 1)?result[(i/2)]+1:(result[(i/2)]);
        }
        return result;
    }
};