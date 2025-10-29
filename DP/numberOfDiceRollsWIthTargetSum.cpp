class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>> t;
    int f(int n,int dice,int k,int sum,int target){
       if(dice==n) return sum==target;
       if(t[dice][sum]!=-1) return t[dice][sum];
       int total=0;
       for(int j=1;j<=k;j++){
        if(sum+j<=target){
         total=(total+f(n,dice+1,k,sum+j,target))%mod;
        }
       }
       return t[dice][sum]=total%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        if(target>n*k) return 0;
        t.resize(n+2,vector<int>(target+1,0));
        // return f(n,0,k,0,target);
        // t[n+1][0]=1;
        // for(int i=n-1;i>=0;i--){
        //     int total=0,sum=target;
        //     for(int j=1;j<=k;j++){
        //          if(sum-j>=0) total=(total+t[i+1][sum-j])%mod;
        //     }
        //     t[i][j]=total%mod;

        // }
        // return t[0][0];
        //only 1 possible way to achieve 0 sum from 0 dice
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
        prev[0]=1;
        for(int dice=1;dice<=n;dice++){
            fill(curr.begin(),curr.end(),0);
            for(int sum=1;sum<=target;sum++){
                int total=0;
                for(int face=1;face<=k;face++){
                    if(sum-face>=0){
                        total=(total+prev[sum-face])%mod;
                    }
                }
                curr[sum]=total%mod;
            }
            prev=curr;
        }
        //we need to return number of ways to achieve target from n dices
        return prev[target];
    }
};