class Solution {
public:
    int numSteps(string s) {
    //   int stepCount=0;
    //   while(s.size()>1){
    //   if(s.back()=='0') s.pop_back();
    //   else{
    //       //odd case
    //       int i=s.size()-1;
    //       while(i>=0 && s[i]!='0'){
    //         s[i]='0';
    //         i--;
    //       }
    //       if(i>=0 ) s[i]='1';
    //       else s.insert(s.begin(),'1');
    //   }
    //   stepCount++;
    //   }
    //   return stepCount;
    int ops=0;
    int  carry=0;
    int n=s.size();
    for(int i=n-1;i>=1;i--){
       if(((s[i]-'0')+carry) & 1 ){
        ops+=2;
        carry=1;
       }
       else ops+=1;
    }
    return ops+carry;
    }
};