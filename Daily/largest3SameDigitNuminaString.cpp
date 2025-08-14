#include <string>
using namespace std;
class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int n=num.size();
        int i=0,j=0;
        int cnt=0;
        // vector<string> res={"999" ,"888","777","666","555","444","333","222","111","000"};
        char maxChar='\0';
        // for(int i=0;i<10;i++){
        //     if(num.contains(res[i])){
        //         ans+=res[i];
        //         break;
        //     }
        // }
        // return ans;
        for(int i=2;i<num.size();i++){
            if(num[i]==num[i-1]  &&  num[i]==num[i-2]){
                maxChar=max(maxChar,num[i]);
            }
        }
        if(maxChar=='\0') return "";
        return string(3,maxChar);
    }
};