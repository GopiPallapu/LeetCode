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
    same as reverse nodes in k pairs but here k is constant as 2 logic is same
    TC => O(n)
    SC => O(1)
 */
class Solution {
public:
     void reverse(ListNode* s, ListNode* e)
    {
        ListNode * p=NULL, *c=s,*n=s->next;
        while(p!=e)
        {
          c->next = p;
          p=c;
          c=n;
          if(n!=NULL)n=n->next;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next  =head;
         ListNode *beforeStart = dummy, *e = head;
        int i=0;
        while(e!= NULL)
        {
            i++;
            if(i%2 == 0)
            {
              // reverse
              ListNode * s= beforeStart->next , *temp = e->next;
              reverse(s,e);
              beforeStart->next = e;
              s->next = temp;
              beforeStart = s;
              e = temp;
            }
            else
            {
              e = e->next;
            }
        }
        return dummy->next;
    }
};