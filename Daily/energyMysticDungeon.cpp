class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> dp(n,INT_MIN);
        int lastK=k;
        for(int i=n-1;i>=0;i--){
           if(lastK>0){
            dp[i]=energy[i];
            lastK--;
           }
           else{
            dp[i]=dp[i+k]+energy[i];
           }
        }
        return *max_element(begin(dp),end(dp));
        
    }
};