#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
         vector<int> freq(501,0);
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        int ans=-1;
        for(int i=1;i<501;i++){
               if(freq[i]==i){
                ans=max(ans,freq[i]);
               }
    }
    return ans;
    }
};