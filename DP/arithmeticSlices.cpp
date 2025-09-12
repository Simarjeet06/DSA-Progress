#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //we extend an arithmetic subsequence if an arithmetic subsequence with same difference is possible at previous index.
        int n=nums.size();
        int result=0;
        //for each index we store the frequency of arithmetic subsequence with given difference.
        vector<unordered_map<long long,int>> mpp(n);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff=((long long)nums[i]-(long long)nums[j]);
                if(mpp[j].count(diff)>0){
                    mpp[i][diff]+=mpp[j][diff]+1;
                    if(mpp[i][diff]>=2){
                        result+=mpp[j][diff];
                    }
                }
                else mpp[i][diff]++;
            }
        }
        return result;
    }
};