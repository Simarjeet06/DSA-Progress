
#include<vector>
#include<algorithm>
using namespace std; 

class Solution {

public:
    char kthCharacter(long long k, vector<int>& operations) {

        // sol 1
        /*long long len=1;
        int it=0;
        while(len<k){
            len*=2;
            it++;
        }

        int cnt=0;

        while(k>1){
          if(k>(len/2) && operations[it-1]==1) cnt++;
          if(k>(len/2)){
            k-=(1ll<<(it-1));
          }
          it--;
          len/=2;
        }
        return 'a' + (cnt%26);
        */
        long long  mask=0;
        for(int i=0;i<min(63, (int) operations.size());i++){
            mask |=(1ll* operations[i]<<i);
        }
        // we count only when the operation is 1 and k>(len/2) or present in the right half ; there are a total shifts of k-1 from k=1 uptil k and we represent this in binary to indicate the fact that the respective k lies in the right half; so we count the and operation of shifts and mask;set mask bit indicates operation==1.
        return 'a'+ (__builtin_popcountll((k-1) & mask))%26;
    }
};