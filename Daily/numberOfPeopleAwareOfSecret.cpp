#include<vector>
#include<cstring>
using namespace std;
class Solution {
public:
    int MOD=1e9+7;
    int days[1001];
    int solve(int day,int delay,int forget){
        if(day==1) return 1;
        long long total=0;
        if(days[day]!=-1) return days[day];
        for(int prev=day-forget+1;prev<=day-delay;prev++){
            if(prev>0) total=(total+solve(prev,delay,forget))%MOD;
        }
        return days[day]=total;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long res=0;
        // memset(days,-1,sizeof(days));
        vector<int> t(n+1,0);
        // for(int day=n-forget+1;day<=n;day++){
        //     if(day>0){
        //         res=(res+solve(day,delay,forget))%MOD;
        //     }
        // }
        // return res;
        t[1]=1;
        int count=0;
        for(int i=2;i<=n;i++){
            if(i-delay>0) count=(count+t[i-delay])%MOD;
            if(i-forget>0) count=(count-t[i-forget]+MOD)%MOD;
            t[i]=count;
           }
    
        int result=0;
        for(int day=n-forget+1;day<=n;day++){
            if(day>0) result=(result+t[day])%MOD;
        }
        return result;
    }
};