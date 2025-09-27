class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==0 || right==0) return 0;
        // int cnt=0;
        // while(left!=right){
        //     left>>=1;
        //     right>>=1;
        //     cnt++;
        // }
        // cout<<cnt<<endl;
        // left<<=cnt;
        // return left;
        while(right>left){
            //clearing right most set bits until both the numbers are not equal since if we will have a common prefix we will achieve this we will get a value greater than zero and if we don't we will ultimately get zero.
            right=(right & (right-1));
        }
        return right;
    }
};