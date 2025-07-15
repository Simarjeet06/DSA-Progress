#include<string>
#include<unordered_set>
#include<ctype.h>
using namespace std;
class Solution {
public:
    bool isValid(string word) {
        int cntVowel=0;
        int cntConsonant=0;
        unordered_set<char> vowels={'a','e','i','o','u'};
        if(word.size()<3) return false;
            for(char c:word){
                if(isalpha(c)){
                    if(vowels.count(tolower(c))){
                        cntVowel++;
                    }
                    else{
                        cntConsonant++;
                     }
                }
                else if(!isdigit(c)) return false;

            }
        return cntVowel>=1 && cntConsonant>=1;
    }
};