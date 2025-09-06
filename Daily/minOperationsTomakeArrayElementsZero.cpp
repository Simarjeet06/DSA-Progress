#include<climits>
#include<vector>
using namespace std;
class Solution {
public:
    long long solve(int l,int r){
        long long L=1;
        long long s=1;
        long long steps=0;
        // TC->0(log(r) to base 4)
        while(L<=r){
             long long R=4*L-1;
                long long start=max((long long)l,L);
                long long end=min((long long)r,R);
                 if(start<=end){
                     long long range=(end-start+1);
                    steps+=(range)*s;
                }
                s++;
                L*=4;
        }
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long total=0;
        int n=queries.size();
        for(int i=0;i<n;i++){
            long long l=queries[i][0];
            long long r=queries[i][1];
            long long step=solve(l,r);
            // tc->o(queries*log(r))
            total+=(step+1)/2;
        }
        return total;
    }
};