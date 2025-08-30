#include<string>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ops1=0,ops2=0;
        for(int i=0;i<n;i++){
           char expectedZero=(i%2==0)?'0':'1';
           char expectedOne=(i%2==0)?'1':'0';
           if(s[i]!=expectedZero) ops1++;
           if(s[i]!=expectedOne) ops2++;
        }
        return min(ops1,ops2);
    }
};