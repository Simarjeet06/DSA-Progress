/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* node){
         ListNode* prev=nullptr;
         while(node){
            ListNode* nextNode=node->next;
            node->next=prev;
            prev=node;
            node=nextNode;
         }
         return prev;
     }
    int pairSum(ListNode* head) {
        //first we will find the mid of linked list using slow and fast pointers
        //then we reverse the second half and make comparisons to compute the sum
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=reverseLL(slow);
        ListNode* first=head;
        int maxi=0;
        while(second){
          maxi=max(maxi,first->val+second->val);
          first=first->next;
          second=second->next;
        } 
        return maxi;

    }
};