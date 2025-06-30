#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> freq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        sort(nums.begin(),nums.end());
        int ans=0;
        int left=0;
        int right=n-1;
        while(left<=right){
            if(freq.find(nums[left]+1)!=freq.end()){
                ans=max(ans,freq[nums[left]]+freq[nums[left]+1]);
            }
            left++;
        }
        return ans;
    }
};