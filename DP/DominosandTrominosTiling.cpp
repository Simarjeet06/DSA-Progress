#include<vector>
using namespace std;
class Solution {
public:
    // int solve(int n){
    //     if(n<=0) return 1;
    //     if(n==1 || n==2) return n;
    //     return (2*solve(n-1)+solve(n-3)); 

    // }
    int numTilings(int n) {
        // return solve(n);
        int mod=1e9+7;
        vector<int> t(n+1,0);
        if(n<=1) return 1;
        t[0]=1;
        t[1]=1;
        t[2]=2;
        for(int i=3;i<=n;i++){
            t[i]=((2*t[i-1])%mod+t[i-3])%mod;
        }
        return t[n];
    }
};