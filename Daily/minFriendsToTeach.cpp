#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        //we need to make sure that friends unable to communicate with each other are able to do so with the most common language among these set of friends ;so we teach among these friends the most common language only to those who do not know this language.
        
        // first we find out who needs to be taught this is if a pair of friends of no common language of communication.
        set<int> needTeach;
        for(auto& f:friendships){
            int u=f[0];
            int v=f[1];
            bool canCommunicate=false;
            for(int langu:languages[u-1]){
                for(int langv: languages[v-1]){
                    if(langu==langv){
                        canCommunicate=true;
                        break;
                    }
                }
            }
            if(!canCommunicate){
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }
        //most frequent language among non-communicating friends
        vector<int> freq(n+1,0);
        for(int person:needTeach){
            for(int lang:languages[person-1]){
                freq[lang]++;
            }
        }
        //we need to find the maximum number of people who know a common language among non communicating individuals and teach those who do not know this language.
        int maxKnown=0;
        for(int i=1;i<=n;i++){
          maxKnown=max(maxKnown,freq[i]);
        }
        return needTeach.size()-maxKnown;
    }
};