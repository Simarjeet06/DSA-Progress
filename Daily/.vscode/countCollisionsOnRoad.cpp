class Solution {
public:
    int countCollisions(string directions) {
    //     stack<char> st;
    //     int ops=0;
    //     for(char d:directions){
    //         if(d=='L'){
    //            if(!st.empty() && st.top()=='R'){
    //             ops+=2;
    //             st.pop();
    //            while(!st.empty() && st.top()=='R'){
    //             ops++;
    //             st.pop();
    //            }
    //            st.push('S');
    //            }
    //         else if(!st.empty() && st.top()=='S'){
    //           ops++;
    //           st.push('S');
    //         }
    //         else st.push('L');
    //     }
    //     else if(d=='S'){
    //         while(!st.empty() && st.top()=='R'){
    //             ops++;
    //             st.pop();
    //         }
    //         st.push('S');
    //     }
    //     else{
    //         st.push(d);
    //     }
    // }
    // return ops;
    int res=0;
    int n=directions.size();
    int i=0,j=n-1;
    while(i<n && directions[i]=='L') i++;
    while(j>=0 && directions[j]=='R') j--;
    if(i>=j) return res;
    for(int k=i;k<=j;k++){
        if(directions[k]!='S') res++;
    }
    return res;
    }
};