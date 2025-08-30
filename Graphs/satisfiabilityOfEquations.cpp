#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> parent,sz;
    int findPar(int i){
        if(i==parent[i]) return i;
        return parent[i]=findPar(parent[i]);
    }
    void unionDo(int x,int y){
        int parX=findPar(x);
        int parY=findPar(y);
        if(parX== parY) return;
        if(sz[parX]<sz[parY]){
            parent[parX]=parY;
            sz[parY]+=sz[parX];
        }
        else{
            parent[parY]=parX;
            sz[parX]+=sz[parY];
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        sz.resize(26,1);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='='){
                int num1=equations[i][0]-'a';
                int num2=equations[i][3]-'a';
                unionDo(num1,num2);
            }
        }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='!'){
                int num1=equations[i][0]-'a';
                int num2=equations[i][3]-'a';
                int par1=findPar(num1);
                int par2=findPar(num2);
                if(par1==par2) return false; 
            }
        }
        return true;
    }
};