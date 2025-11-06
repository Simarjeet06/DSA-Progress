class Solution {
public:
vector<long long> res;
set<pair<int,int>> mains,sec;
unordered_map<int,int> mpp;
long long sum=0;

void insertIntoSet(pair<int,int> p,int x){
    if(mains.size()<x || p>*(mains.begin())){
        mains.insert(p);
        sum+=1LL*(p.first)*(p.second);
        if(mains.size()>x){
            auto smallest=*mains.begin();
            sum-=1LL*(smallest.first)*(smallest.second);
            mains.erase(smallest);
            sec.insert(smallest);
        }
    }
    else{
        sec.insert(p);
    }
}
void removeFromSet(pair<int,int> p){
    if(mains.find(p)!=mains.end()){
       sum-=(p.first)*1LL*(p.second);
       mains.erase(p);
       if(!sec.empty()){
        auto largest=*sec.rbegin();
        sec.erase(largest);
        mains.insert(largest);
        sum+=1LL* (largest.first)*(largest.second);
       }
    }
    else{
        sec.erase(p);
    }
}
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
            if(mpp[nums[j]]>0){
                removeFromSet({mpp[nums[j]],nums[j]});
            }
            mpp[nums[j]]++;
            insertIntoSet({mpp[nums[j]],nums[j]},x);
            if(j-i+1==k){
                res.push_back(sum);
                removeFromSet({mpp[nums[i]],nums[i]});
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                else{
                    insertIntoSet({mpp[nums[i]],nums[i]},x);
                }
                i++;
            }
            j++;
        }
        return res;
    }
};