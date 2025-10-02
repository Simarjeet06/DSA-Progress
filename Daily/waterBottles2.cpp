class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        //numBottles->implies the number of full bottles i have initially
        //numExchange->we can exchange numExchange empty bottles with 1 full water bottle
        //brute force:using simulation
    
        int emptyBottles=numBottles;
        int bottlesDrunk=numBottles;
        while(emptyBottles>=numExchange){
          emptyBottles-=numExchange;
          numExchange+=1; 
            emptyBottles++;
             bottlesDrunk++;    
          }
        return bottlesDrunk;
    }
};