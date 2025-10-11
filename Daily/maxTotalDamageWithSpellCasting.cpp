class Solution {
public:
    int n;
    // long long t[100001];
    // long long f(vector<int>& vals,int i,unordered_map<int,int>& mpp){
    //     if(i>=vals.size()) return 0;
    //     long long pick=0,skip=0;
    //     if(t[i]!=-1) return t[i];
    //     long long damage=mpp[vals[i]]*1LL*vals[i];
    //     int nextIdx=upper_bound(begin(vals),end(vals),vals[i]+2)-begin(vals);
    //     skip=f(vals,i+1,mpp);
    //     pick=damage+f(vals,nextIdx,mpp);
    //     return t[i]=max(pick,skip);
    // }
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,int> mpp;
        // memset(t,0,sizeof(t));
        n=power.size();
        for(int i=0;i<n;i++){
            mpp[power[i]]++;
        }
        vector<int> vals;
        for(auto [k,freq]:mpp){
            vals.push_back(k);
        }
        sort(begin(vals),end(vals));
        // return f(vals,0,mpp);
        int x=vals.size();
        vector<long long> t(x+1,0);
        for(int i=x-1;i>=0;i--){
            int nextIdx=upper_bound(begin(vals),end(vals),vals[i]+2)-begin(vals);
            long long damage=mpp[vals[i]]*1LL*vals[i];
            t[i]=max(t[i+1],damage+t[nextIdx]);
        }
        return t[0];
    }
};