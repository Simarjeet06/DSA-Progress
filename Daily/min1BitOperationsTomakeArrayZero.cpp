class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<long long> f(31,0);
        //number of operations to make numbers with 1 bit set to zero.
        f[0]=1;
        for(int i=1;i<=30;i++){
            f[i]=1LL*2*f[i-1]+1;
        }
        int sign=1;
        int ans=0;
        for(int i=30;i>=0;i--){
            //alternately adding the positions that have set bits 
            int ithBit=(n>>i) & 1;
            if(ithBit){
                ans+=(sign*(int)f[i]);
                sign=(sign==1)?-1:1;
            }
        }
        return ans;
    }
};