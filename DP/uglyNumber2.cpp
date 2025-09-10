#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    // priority_queue<long long,vector<long long>,greater<long long>> pq;
    long long nthUglyNumber(int n) {
        // unordered_set<long long> st;
        // pq.push(1);
        // st.insert(1);
        // long long ans=0;
        // while(n--){
        //    long long top=pq.top();
        //    ans=top;
        //    pq.pop();
        //   long long nextVals[3]={top*2,top*3,top*5};
        //   for(long long val:nextVals){
        //     if(st.find(val)==st.end()){
        //         st.insert(val);
        //         pq.push(val);
        //     }
        //   }
        // }
        // return ans;

        //Approach-2:
        vector<long long> t(n+1,0);
        //state defination: t[i]->ith ugly number 
        t[1]=1;
        int ind2=1,ind3=1,ind5=1;
        long long i2,i3,i5;
        for(int i=2;i<=n;i++){
            i2=t[ind2];
            i3=t[ind3];
            i5=t[ind5];
            if((i2*2)<=(i3*3) && (i2*2)<=(i5*5)){
                t[i]=i2*2;
                ind2++;
            }
             if((i3*3)<=(i2*2) && (i3*3)<=(i5*5)){
                t[i]=i3*3;
                ind3++;
            }
             if((i5*5)<=(i2*2) && (i5*5)<=(i3*3)){
                t[i]=i5*5;
                ind5++;
            }
        }
        return t[n];
    }
};