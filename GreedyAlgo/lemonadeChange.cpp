#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills){
        int five=0,ten=0;
       for(int i=0;i<bills.size();i++){
          if(bills[i]==5){
          five++;
            continue;
          }
          else if(bills[i]==10){
            if(five>=1){
                five--;
                ten++;
                continue;
            }
            else return false;
          }
          else{
            if(five>=1 && ten>=1){
                five--;
                ten--;
                continue;
            }
            else if(five>=3){
                five-=3;
            }
            else return false;
          }
       }
       return true;
    }
};