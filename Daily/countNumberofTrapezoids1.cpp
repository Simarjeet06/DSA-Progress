class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,long long> mpp;
        int mod=1e9+7;
        for(auto p:points){
            mpp[p[1]]++;
        }
        for(auto it=mpp.begin();it!=mpp.end();it++){
            int pts=it->second;
            mpp[it->first]=1LL*pts*(pts-1)/2;
        }
        long long total=0,sum=0;
        for(auto it=mpp.begin();it!=mpp.end();it++){
            total=(total+(sum*it->second)%mod)%mod;
            sum=(sum+it->second);
        }
        return (int)total;
    }
};