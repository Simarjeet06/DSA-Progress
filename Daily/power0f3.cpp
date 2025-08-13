class Solution {
public:
    bool f(int n){
        if(n<=0) return false;
         if(n%3==0){
           return f(n/3);
        }
         if(n==1) return true;
        return false;
    }
    bool isPowerOfThree(int n) {
        //approach-1
    //    if(n<=0) return false;
    //    double exp=log10(n)/log10(3);
    //    return ((exp-(int)exp)==0);

    //approach-2
        //   return f(n);

    //approach-3 
    return (n>0 && (1162261467%n ==0));
    }
};