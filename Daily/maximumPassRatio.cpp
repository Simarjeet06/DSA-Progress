#include<vector>
#include<queue>
using namespace std;    
class Solution {
public:
   priority_queue<pair<double,int>> pq;
   //we store the {delta,classInd} in priority queue.
   //we try inserting a new student that shows improvement in pass ratio during each iteration; so that the overall average pass ratio maximises.
   double findDelta(int i,vector<vector<int>>& classes){
    int currPass=classes[i][0];
    int totalPass=classes[i][1];
    double curr=((double)currPass/(double)totalPass);
    int potentialPass=classes[i][0]+1;
    int totalPotential=classes[i][1]+1;
    double potential=((double)potentialPass/(double)totalPotential);
    return (potential-curr);
   }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        for(int i=0;i<n;i++){
            double deltaVal=findDelta(i,classes);
            pq.push({deltaVal,i});
        }
        while(extraStudents--){
            auto it=pq.top();
            pq.pop();
            classes[it.second][0]++;
            classes[it.second][1]++;
            pq.push({findDelta(it.second,classes),it.second});
            
        }
        
        double res=0.0;
        while(!pq.empty()){
            double val=(double)(classes[pq.top().second][0])/(classes[pq.top().second][1]);
            pq.pop();
            res+=val;
        }
        res/=(classes.size());
return res;
    }
};