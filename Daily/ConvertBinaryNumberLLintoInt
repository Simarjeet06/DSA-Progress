#include <iostream>
#include <cmath>
using namespace std;
//   Definition for singly-linked list.
  struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        ListNode* prev=head;
        if(head->next==nullptr) return head;
        ListNode* curr=head->next;
        prev->next=nullptr;
        while(curr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;

        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
       /* string num="";
        ListNode* node=head;
        while(node){
            num+=node->val;
            node=node->next;
        }
        int ans=0;
        int n=num.size();
        for(int i=0;i<num.size();i++){
            if(num[i]==1){
                ans+=(num[i])*pow(2,n-i-1);
            }
            else continue;
        }
        return ans;
        */
        //approach-1 (without extra space by reversing linked list)
        ListNode* newHead=reverseLL(head);
        int exp=0;
        int res=0;
        while(newHead){
            // cout<<newHead->val<<" ";
            // newHead=newHead->next;
            res+=(newHead->val)*pow(2,exp);
            exp++;
            newHead=newHead->next;
        }
return res;
        //approach-2 (optimal approach)
        // int result=0;
        // while(head){
        //     result=(result<<1) | (head->val);
        //     head=head->next;
        // }
        // return result;
    }
};