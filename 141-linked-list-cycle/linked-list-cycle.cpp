/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
    TC -> O(n+k)k is constant to detect loop SC-> O(1) using two pointer approach
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return false;
        ListNode* fast=head,*slow = head;
        while(fast!=NULL && fast->next!=NULL)
        {
          slow = slow->next;
          fast = fast->next->next;
          if(fast==slow)return true;
        }
        return false;
    }
};