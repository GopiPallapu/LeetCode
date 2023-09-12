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
    /*
        Approach:
        Start with tail node iterate and find non duplicate node and attatch it to tail next and move tail pointer 
        TC => O(n)
        SC => O(1)
    */
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL )return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        ListNode* temp = head;
        while(temp != NULL )
        {
            if(temp->next != NULL && temp->val == temp->next->val)
            {
                while(temp->next != NULL && temp->val == temp->next->val)
                {
                    temp = temp->next;
                }
                tail->next = temp->next;
                //tail = temp->next;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};