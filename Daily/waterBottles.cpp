class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // int bottles=numBottles;
        // int ans=bottles;
        // while(bottles>=numExchange){
        //     int newFull=bottles/numExchange;
        //     ans+=newFull;
        //     int leftOver=bottles%numExchange;
        //     bottles=newFull+leftOver;

        // }
        // return ans;
        return (numBottles+((numBottles-1)/(numExchange-1)));
    }
};