#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(int num:asteroids){
           bool destroyed=false;
            while(!st.empty() && num<0 && st.top()>0){
                if(abs(st.top()<abs(num))){
                    st.pop();
                    continue;
                }
                else if(abs(st.top())==abs(num)){
                    st.pop();

                }
                destroyed=true;
                break;
            }
           
           if(!destroyed) st.push(num);
        }
    
       
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
