struct compFunc{
     bool operator()(const pair<int,int>& a,const pair<int,int>& b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first>b.first;
     }
};
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        int i=0,j=0;
        while(j<n){
            mpp[nums[j]]++;
            if(j>=k-1){
                 priority_queue<pair<int,int>,vector<pair<int,int>>,compFunc> pq;
                for(auto it=mpp.begin();it!=mpp.end();it++){
                    pq.push({it->second,it->first});
                    if(pq.size()>x) pq.pop();
                }
                int sum=0;
                while(!pq.empty()){
                    sum+=(pq.top().first)*(pq.top().second);
                    pq.pop();
                }
                ans.push_back(sum);
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};