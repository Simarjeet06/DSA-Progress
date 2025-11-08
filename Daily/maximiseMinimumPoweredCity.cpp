class Solution {
public:
    int n;
    bool possible(vector<long long>& diff,long long mid,int r,int k){
        vector<long long> temp=diff;
        long long cumSum=0;
        for(int i=0;i<n;i++){
             cumSum+=temp[i];
            if(cumSum<mid){
                long long need=mid-cumSum;
                if(need>k) return false;
                cumSum+=need;
                k-=need;
                if(i+2*r+1<n) temp[i+2*r+1]-=need;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        n=stations.size();
        vector<long long> diff(n,0);
        long long sum=0;
        for(int i=0;i<n;i++) sum+=stations[i];
        long long l=*min_element(begin(stations),end(stations));
        long long right=sum+k;
        long long ans=l;
        for(int i=0;i<n;i++){
            diff[max(0,i-r)]+=stations[i];
            if(i+r+1<n) diff[i+r+1]-=stations[i];

        }
        while(l<=right){
            long long mid=l+(right-l)/2;
            if(possible(diff,mid,r,k)){
                ans=mid;
                l=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
};