class Solution {
public:
    string decode(const string& s,int& i){
        string res;
        int num=0;
        while(i<s.size()){
            char ch=s[i];
            if(isdigit(ch)){
                num=num*10+(ch-'0');
                i++;
            }
            else if(ch=='['){
                i++;
               string t=decode(s,i);
               for(int k=0;k<num;k++){
                    res+=t;
                }
                num=0;
            }
            else if(ch==']'){
                i++;
                return res;
            }
            else {
                res+=ch;
                i++;
            }
        }
        return res;
    }
    string decodeString(string s) {
        //solving using recursion
        //[->start decoding 
        //]->time to append
        // int i=0;
        // return decode(s,i);
        stack<char> st;
        string res;
        for(int i=0;i<s.size();i++){
          char ch=s[i];
          if(ch!=']'){
            st.push(ch);
          }
          else{
            string temp;
            while(!st.empty() && st.top()!='['){
                temp+=st.top();
                st.pop();
            }
            st.pop();
            reverse(begin(temp),end(temp));
            string num="";
            while(!st.empty() && isdigit(st.top())){
                num+=st.top();
                st.pop();
            }
            reverse(begin(num),end(num));
            int n=stoi(num);
            for(int i=0;i<n;i++){
               for(char c:temp){
                st.push(c);
               }
            }
          }

        }
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};