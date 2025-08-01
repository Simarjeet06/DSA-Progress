#include<unordered_set>
using namespace std;
class Solution {
public:
//understanding time complexity of the code; since for OR operation when we have one bit set it cannot be unset ; therefore, we can have a max of 32 values in a set; so for each element  the set will contain 32 elements at max and hence time complexity will be o(n*32).
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> res;
        for(auto el: arr){
            for(auto it:prev){
                curr.insert(it|el);
                res.insert(it|el);
            }
            curr.insert(el);
            res.insert(el);
            prev=curr;
            curr.clear();
           
        }
        return res.size();
    }
};