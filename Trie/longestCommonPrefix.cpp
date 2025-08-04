#include<string>
#include<vector>
using namespace std;
struct Node{
    Node* links[26];
    int cntPrefix=0;
    bool containsKey(char ch){
        return links[ch-'a']!=nullptr;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void incrementPrefix(){
        cntPrefix++;
    }
    int getPrefix(){
        return cntPrefix;
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
       root=new Node();
    }
    void insert(string word){
        Node* node=root;
        node->incrementPrefix();
        for(char ch:word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node=node->get(ch);
             node->incrementPrefix();
        }
    }
    string longestPrefix(int n){
        Node* node=root;
        string ans="";
            while(node->getPrefix()==n){
                int cnt=0;
                int ind=-1;
                for(int i=0;i<26;i++){
                    if(node->links[i]!=nullptr){
                        if(node->links[i]->getPrefix()==n){
                            cnt++;
                           ind=i;
                        }
                    }
                }
             if(cnt==1){

                            ans+='a'+ind;
                            node=node->links[ind];
                        
                    }
                    else break;
    }
    return ans;
    }

};


class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        int n=strs.size();
        for(string s:strs){
            t.insert(s);
        }
        return t.longestPrefix(n);
    }
};