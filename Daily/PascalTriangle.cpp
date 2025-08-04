#include<vector>
using namespace std;
class Solution {
public:
   vector<int> generateRow(int r){
    vector<int> temp;
    temp.push_back(1);
    long long res=1;
    for(int i=1;i<r;i++){
        res*=(r-i);
        res/=(i);
        temp.push_back(res);
    }
    return temp;
   }
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> ans;
       for(int i=1;i<=numRows;i++){
         ans.push_back(generateRow(i));
       }
       return ans;
    }
};