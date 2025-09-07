#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        int left=-1;
        int right=1;
        if(n & 1){
        ans[n/2]=0;
        for(int i=(n/2)-1;i>=0;i--){
            ans[i]=left;
            left--;
        }
        for(int i=(n/2)+1;i<n;i++){
            ans[i]=right;
            right++;
        }
        }
        else{
        for(int i=(n/2)-1;i>=0;i--){
            ans[i]=left;
            left--;
        }
          for(int i=(n/2);i<n;i++){
            ans[i]=right;
            right++;
        }
        }
        return ans;
    }
};