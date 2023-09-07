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
    void print(ListNode* head)
    {
        ListNode *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->val<< " ";
            temp = temp->next;
        }
        cout<<endl;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        // move pre to left positions
        int i =0;
        while(i < left-1)
        {
            prev = prev->next;
            i++;
        }
        ListNode* curr = prev->next;
        // reverse nodes from current node to right nodes
        i =0;
        while(i < right-left)
        {
            ListNode *n  =prev->next;
            prev->next = curr->next;
            curr->next =curr->next->next ;
            prev->next->next = n;
            print(head);
            i++;

        }
        return dummy->next;
    }
};