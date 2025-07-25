#include<string>
using namespace std;
struct Node{
    Node* links[26];
    int cntEndsWith=0;
    int cntPrefix=0;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void increaseEnd(){
        cntEndsWith++;
    }
    void deleteEnd(){
        cntEndsWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    int getPrefix(){
        return cntPrefix;
    }
    int getEnd(){
        return cntEndsWith;
    }

};
class Trie{
    private: 
    Node* root;

    public:

    Trie(){
        // Write your code here.
        root=new Node();

    }

    void insert(string &word){
        // Write your code here.
        Node* node=root;
        for(char ch: word){
           if(!node->containsKey(ch)){
               node->put(ch,new Node());
           }
           node=node->get(ch);
           node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node=root;
        for(char ch: word){
           if(!node->containsKey(ch)) return 0;
           node=node->get(ch);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node=root;
        for(char ch : word){
            if(!node->containsKey(ch)) return 0;
            node=node->get(ch);
        }
       return  node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
         Node* node=root;
         for(char ch : word){
             node=node->get(ch);
             node->reducePrefix();
         }
         node->deleteEnd();

    }
};
