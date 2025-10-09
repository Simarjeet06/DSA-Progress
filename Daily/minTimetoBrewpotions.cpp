class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<long long> finishTime(n,0);
        for(int j=0;j<m;j++){
            finishTime[0]+=skill[0]*mana[j]*1LL;
            for(int i=1;i<n;i++){
                finishTime[i]=max(finishTime[i-1],finishTime[i])+(1LL*skill[i]*mana[j]);
            }
            //correction
            for(int i=n-1;i>0;i--){
                finishTime[i-1]=finishTime[i]-(1LL*skill[i]*mana[j]);
            }
        }
        return finishTime[n-1];
    }
};