#include<unordered_map>
#include<string>
using namespace std;
struct Node{
    unordered_map<char,Node*> links;
    bool containsKey(char ch){
        return links.count(ch);
    }
    Node* get(char ch){
        return links[ch];
    }
    void put(char ch,Node* node){
        links[ch]=node;
    }
  
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void countSubstr(string s,int& cnt){
        Node* node=root;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(!node->containsKey(s[j])){
                    node->put(s[j],new Node());
                    cnt++;
                    
                }
                node=node->get(s[j]);
                
            }
            node=root;
        }
     
    }
     void freeMemory(Node* node){
        for(auto& pair:node->links){
            freeMemory(pair.second);
        }
        delete node;
    }
    ~Trie(){
        freeMemory(root);
    }
    
};

/*You are required to complete this method */
int countDistinctSubstring(string s) {
    // Your code here
    Trie t;
    int cnt=1;
   t.countSubstr(s,cnt);
   return cnt;
    
    
}