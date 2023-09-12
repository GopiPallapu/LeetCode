/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
    Approach :
    TC => O(n)
    SC => O(1)
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL )return head;
        ListNode* odd  =head , *oddIndex = head;
        ListNode* even = head->next ,*evenIndex = head->next;
        while(oddIndex->next != NULL && evenIndex->next != NULL)
        {
            oddIndex->next = evenIndex->next;
            oddIndex = oddIndex->next;
            evenIndex->next = oddIndex->next;
            evenIndex  = evenIndex->next;
        }
        oddIndex->next = even;
        return odd;
    }
};