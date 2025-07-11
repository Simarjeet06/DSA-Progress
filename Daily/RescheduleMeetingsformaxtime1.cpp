#include <vector>
using namespace std;
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        freeTime.push_back(startTime[0]-0);
        for(int i=1;i<startTime.size();i++){
           freeTime.push_back(startTime[i]-endTime[i-1]);
        }
        freeTime.push_back(eventTime-endTime[endTime.size()-1]);
        int i=0;
        int j=0;
        int maxi=0;
        int sum=0;
       
       
        while(j<freeTime.size()){
            if(j-i+1>k+1){
                sum-=freeTime[i];
                i++;
            }
            sum+=freeTime[j];
            j++;
            maxi=max(maxi,sum);

        }
        return maxi;
    }
};