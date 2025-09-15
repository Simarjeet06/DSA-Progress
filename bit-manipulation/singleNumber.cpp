#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
       for(int i=0;i<=31;i++){
        int temp=(1<<i);
        int cnt=0;
        for(int num:nums){
            if((temp & num)!=0) cnt++;
        }
        if((cnt%3)!=0) result|=temp;
       }
       return result;
    }
};