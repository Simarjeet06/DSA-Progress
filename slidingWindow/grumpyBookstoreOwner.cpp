
#include<vector>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int i=0;
        int extra=0,base=0;
        //base defines the already satisfied customers we do not tamper that all we try to find is the max unsatisfied customers in a window of size minutes and then we try to satisfy this extra bunch.
        int maxExtra=0;
        for(int j=0;j<n;j++){
            if(!grumpy[j]) base+=customers[j];
            else extra+=customers[j];
            if(j>=minutes-1){
                maxExtra=max(maxExtra,extra);
                if(grumpy[i]){
                    extra-=customers[i];
                }
                i++;
            }
        }
        return maxExtra+base;
    }
};