/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
      //without any auxiliary space 
      //insert new nodes to the linked list
      Node* curr=head;
      while(curr){
        Node* nextNode=curr->next;
        Node* newNode=new Node(curr->val);
        curr->next=newNode;
        newNode->next=nextNode;
        curr=nextNode;
      }
      //after creating the new list we need to add random pointers to the new nodes of linked list;
      curr=head;
      while(curr){
        if(!curr->random) curr->next->random=nullptr;
        else{
            curr->next->random=curr->random->next;
        }
        curr=curr->next->next;
      }
      //we need to separate the newly created linked list
      Node* newHead=nullptr;
      curr=head;
      Node* temp=curr->next;
      while(curr && temp){
          if(newHead==nullptr){
            newHead=temp;
          }
          curr->next=(curr->next)?curr->next->next:nullptr;
          temp->next=(temp->next)?temp->next->next:nullptr;
          curr=curr->next;
          temp=temp->next;
      }
      return newHead;
    }
};