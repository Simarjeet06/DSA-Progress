#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> freq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        int ans=0;
        for(auto it:freq){
            int num=it.first;
            if(freq.find(num+1)!=freq.end()){
                ans=max(ans,freq[num]+freq[num+1]);
            }
        }
       
        return ans;
    }
};