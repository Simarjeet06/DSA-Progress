class Solution {
public:
    long long makeTheIntegerZero(long long num1, long long num2) {
        for(long long k=1;k<=36;k++){
            long long num=num1-k*num2;
            if(num<0) break;
            if(num>=k && (__builtin_popcountll(num)<=k)) return k;

        }
        return -1;
    }
};
