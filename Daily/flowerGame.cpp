
typedef long long ll;
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long cnt=0;
        //odd count->ceil(n/2) or(n+1)/2 
        ll odd_n=(n+1)/2;
        ll even_n=(n)/2;
        ll odd_m=(m+1)/2;
        ll even_m=(m/2);
        cnt+=(odd_n*even_m);
        // cnt+=(odd_m*even_n);
        ll res=floor((ll)n*(ll)m/2);
        //we are counting all combinations of odd sum which will lead to Alice's win; odd numbers with even numbers of m and even numbers of n and odd numbers of m;
        return res;
    }
};