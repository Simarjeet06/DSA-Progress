#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
class Solution {
public:
double epsilon=1e-5;
bool solve(vector<double>& cards){
 //Approach -2
        if(cards.size()==1) return(abs(cards[0]-24)<=epsilon);
        for(int i=0;i<cards.size();i++){
            for(int j=0;j<cards.size();j++){
                if(i==j) continue;
                vector<double> temp;
                for(int k=0;k<cards.size();k++){
                    if(k!=i && k!=j) temp.push_back(cards[k]);
                }
                double a=cards[i];
                double b=cards[j];
                vector<double> results={a+b,a-b,b-a,a*b};
                if(fabs(b)>epsilon) results.push_back(a/b);
                if(fabs(a)>epsilon) results.push_back(b/a);
                for(double val:results){
                    temp.push_back(val);
                   if(solve(temp)) return true;
                   temp.pop_back();
                }
            }

        }
        return false;
}
    bool judgePoint24(vector<int>& cards) {
       
       vector<double> nums(cards.begin(),cards.end());
       return solve(nums);
    
     // sort(cards.begin(),cards.end());
        // if(isValid(cards)) return true;
        // while(next_permutation(cards.begin(),cards.end())){
        //     if(isValid(cards)) return true;
        // }
        // return false;
    }
    bool isValid(vector<int>& cards){
        double a=cards[0],b=cards[1],c=cards[2],d=cards[3];
        if(isValid(a+b,c,d) || isValid(a-b,c,d) || isValid(a*b,c,d) || isValid(a/b,c,d)) return true;
        if(isValid(a,b+c,d) || isValid(a,b-c,d) || isValid(a,b*c,d) || isValid(a,b/c,d)) return true;
        if(isValid(a,b,c+d) || isValid(a,b,c-d) || isValid(a,b,c*d) || isValid(a,b,c/d)) return true;
        return false;
    }
    bool isValid(double a,double b,double c){
        if(isValid(a+b,c) || isValid(a-b,c) || isValid(a*b,c) || (b && isValid(a/b,c))) return true;
         if(isValid(a,b+c) || isValid(a,b-c) || isValid(a,b*c) || (c && isValid(a,b/c))) return true;

         return false;
    }

    bool isValid(double a,double b){
       if(abs(a+b-24)<=1e-5  || abs(a-b-24)<=1e-5  ||  abs(a*b-24)<=1e-5  || (b &&  abs(a/b-24)<=1e-5 )) return true;
        return false;
    }
};