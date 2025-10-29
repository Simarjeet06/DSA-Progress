class Solution {
public:
    int smallestNumber(int n) {
    //   return (1<<(1+int(log2(n))))-1;
    for(uint i=0;n & (n+1) ;i ++){
        n|=1<<i;
    }
    return n;
    }
};