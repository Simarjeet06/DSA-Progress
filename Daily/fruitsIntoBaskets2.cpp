#include<vector>
using namespace std;
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int unplaced=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i]){
                  baskets[j]=0;
                  unplaced--;
                     break;
                }
            }
        }
        return unplaced;
    }
};