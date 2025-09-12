#include<string>
using namespace std;
class Solution {
public:
    bool doesAliceWin(string s) {
        string str="aeiou";
        int cntVowel=0;
        for(char ch:s){
            if(str.find(ch)!=string::npos) cntVowel++;
        }
        if(cntVowel==0) return false;
        return true;
    }
};