#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        //freq[0]-> false count,freq[1]->true count
        vector<int> freq(2,0);
        int i=0,j=0;
        int maxi=0;
        while(j<n){
                 if(answerKey[j]=='F') freq[0]++;
                 else freq[1]++;
                 j++;
            
           while(min(freq[0],freq[1])>k){
              if(answerKey[i]=='F') freq[0]--;
              else freq[1]--;
              i++;
           }
              maxi=max(maxi,j-i);
               
        }
        return maxi;
    }
};