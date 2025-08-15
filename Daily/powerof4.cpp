class Solution {
public:
    bool isPowerOfFour(int n) {
        //approach -1 
        if(n<=0) return false;
        // double t=log10(n)/log10(4);
        // if(t==(int)t) return true;
        // return false;


        //approach -2
        // while(n){
        //     if(n==1) return true;
        //     if(n%4!=0) return false;
        //     n/=4;

        // }
        // return true;

        //approach-3
        return( (n>0) && ((n&(n-1))==0) && ((n-1)%3==0));

    }
};