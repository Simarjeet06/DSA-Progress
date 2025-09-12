#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
public:
    typedef pair<int,int> p;
    struct comparisonFunc{
           bool operator()(const p& a,const p& b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
           }
    };
    priority_queue<p,vector<p>,comparisonFunc> pq;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it=mpp.begin();it!=mpp.end();it++){
            pq.push({it->second,it->first});

        }
        vector<int> ans;
        while(!pq.empty()){
            int cnt=pq.top().first;
            int val=pq.top().second;
            pq.pop();
            while(cnt--){
              ans.push_back(val);
            }
        }
        return ans;
    }
};