class Solution {
public:
    int n;
    long long getDescentPeriods(vector<int>& prices) {
        n=prices.size();
        int j=0;
        long long ans=0;
        int currLen=1;
        while(j<n){
            if(j==0 || prices[j]!=prices[j-1]-1){
                currLen=1;

            }
            else{
                currLen++;
            }
            cout<<currLen<<endl;
            ans+=currLen;
            j++;
        
        }
        return ans;
    }
};