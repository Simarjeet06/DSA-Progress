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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0,head);
        ListNode* slow=&dummy;
        ListNode* fast=&dummy;
        // since fast now points to dummy node we need to move it n+1 steps ahead
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }
        //now we need to move both slow and fast simultaneously so that ultimately so that a difference of n is maintained and once fast reaches the end the slow pointer will correctly point to the nth node from end.
        while(fast){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return dummy.next;
    }

};