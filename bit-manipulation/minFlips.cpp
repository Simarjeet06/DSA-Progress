#include<bitset>
class Solution {
public:
    int minFlips(int a, int b, int c) {
        // bitset<32> bit_a(a);
        // bitset<32> bit_b(b);
        // bitset<32> bit_c(c);
        // int flips=0;
        // for(int i=30;i>=0;i--){
        //     int checka=bit_a[i];
        //     int checkb=bit_b[i];
        //     int checkc=bit_c[i];
        //     if((checka == checkc )&& (checkc==checkb)) continue;
        //     if(!checkc){
        //         if(checka && checkb) flips+=2;
        //         else flips+=1;
        //     }
        //     else{
        //        if((checka | checkb)!=1) flips+=1;
        //     }
    // // }
    //      int flips=0;
    //      while(a!=0 || b!=0 || c!=0){
    //         if(c & 1){
    //             if(!(a&1) && !(b&1)) flips++;
    //         }
    //         else{
    //             flips+=(a&1)+(b&1);
    //         }
    //         a>>=1;
    //         b>>=1;
    //         c>>=1;
    //      }
        
        
        // return flips;



        // Approach -2
        int xorCnt=((a|b)^c);
        int cnt1=__builtin_popcount(xorCnt);
        int cnt2=__builtin_popcount((a&b)&(xorCnt));
        return cnt1+cnt2;
    }
};