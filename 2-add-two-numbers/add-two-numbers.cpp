/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
    approach :
    iterating each list adding the nodes and if any carry is there append it to the next nodes and add result
    to tail of dummy nodes
    TC => O(n+n) SC => O(1)
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        int carry =0;
        while(l1 != NULL || l2 !=NULL || carry!=0)
        {
            int x = (l1 != NULL)?l1->val :0;
            int y = (l2 != NULL)?l2->val :0;
            int sum  =x + y + carry;
            int z = sum%10;
            carry = sum / 10;
            ListNode *temp = new ListNode(z);
            tail->next = temp;
            tail = temp;
            l1 = (l1 != NULL)?l1->next :NULL;
            l2 = (l2 != NULL)?l2->next :NULL;
        }
        return dummy->next;
    }
};