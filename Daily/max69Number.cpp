#include<string>
using namespace std;
class Solution {
public:
    // int convert(vector<int>& v){
    //     int temp=0;
    //     for(int el:v){
    //         temp=(temp*10)+el;
    //     }
    //     cout<<temp<<endl;
    //     return temp;
    // }
    int maximum69Number (int num) {
        // vector<int> v;
        // while(num>0){
        //     v.push_back(num%10);
        //     num/=10;
        // }
        // reverse(v.begin(),v.end());
        // for(int i=0;i<v.size();i++){
        //    if(v[i]==6){
        //     v[i]=9;
        //     break;
        //    }
        //    else continue;
        string temp=to_string(num);
        for(char& ch:temp){
            if(ch=='6'){
                ch='9';
                break;
            }
        }
        return   stoi(temp); 
    }
// return convert(v);
        
    
};