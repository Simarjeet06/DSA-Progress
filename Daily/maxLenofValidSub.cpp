#include <vector>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenCnt=0;
        int oddCnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) evenCnt++;
            else oddCnt++;
        }
        int alternating=1;
        int parity=nums[0]%2;
        for(int i=1;i<n;i++){
            int currParity=nums[i]%2;
            if(parity!=currParity){
                 alternating++;
                 parity=currParity;
            }
            else continue;
        }
        return max({evenCnt,oddCnt,alternating});
    }
};