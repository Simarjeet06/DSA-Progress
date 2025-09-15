class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ops=0;
        while(target>startValue){
            ops++;
            if(target%2==0) target/=2;
            else target+=1;
        }
        return (startValue>target)?(startValue-target)+ops:ops;
    }
};