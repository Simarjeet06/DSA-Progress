#include<vector>
#include<set>
#include<string>
#include<queue>
using namespace std;
class Solution {
public:
typedef pair<int,int> p;
queue<p> q;
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> bankset(begin(bank),end(bank));
        if(bankset.find(endGene)==bankset.end()) return -1;
        queue<pair<string,int>> q;
        q.push({startGene,0});
        vector<char> choices={'A','C','G','T'};
        while(!q.empty()){
            string gene=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(gene==endGene) return steps;
            for(int i=0;i<8;i++){
                char old=gene[i];
                for(char ch:choices){
                    if(old==ch) continue;
                    gene[i]=ch;
                    if(bankset.find(gene)!=bankset.end()){
                        q.push({gene,steps+1});
                        bankset.erase(gene);
                    }
                }
                gene[i]=old;
            }
        }
        return -1;
    }
};