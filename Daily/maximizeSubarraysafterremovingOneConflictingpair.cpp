#include<vector>
#include<algorithm>
using namespace std;
#define ALL(x) begin(x),end(x)
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long valid=0;
        vector<vector<int>> conflictingPoints(n+1);
        for(auto &p : conflictingPairs){
            //(a,b)
            int a=min(p[0],p[1]);
            int b=max(p[0],p[1]);
            conflictingPoints[b].push_back(a);
        }
        int maxConflict=0;
        int secondMaxConflict=0;

        vector<long long> extra(n+1,0);
        //extra[i]->number of extra subarrays we gain after removing conflicting point i.

        for(int i=1;i<=n;i++){
               //visiting each point and treating them as subarray ending at this point.
               for(int  &u: conflictingPoints[i]){
                if(u>maxConflict){
                    secondMaxConflict=maxConflict;
                    maxConflict=u;
                }
                else if(u>secondMaxConflict){
                   secondMaxConflict=u;
                }
               }
               valid+=i-maxConflict;
               extra[maxConflict]+=(maxConflict-secondMaxConflict);
        }
        return valid+ *max_element(ALL(extra));
    }
};
