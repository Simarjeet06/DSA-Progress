#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxi=INT_MIN;
        int maxSum=INT_MIN;
        int sum=0;
        // set<int> st;
        vector<int> v(101,-1);
        for(int el:nums){
            maxi=max(maxi,el);
            if(el<0 || (el>0 && v[el]!=-1)){
                continue;
            }
            else{
                sum+=el;
                v[el]=1;
                maxSum=max(maxSum,sum);
            }
        }
        return maxi<0?maxi:maxSum;
    }
};