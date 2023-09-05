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
    // TC => O(n)
    // SC => O(1)
    void copy(Node* head)
    {
        Node *temp=head , *n = head->next;
        while(temp!=NULL)
        {
              Node* val = new Node(temp->val);
             temp->next =val;
             val->next = n;
             temp = n;
             if(n!=NULL)n=n->next;
        }
    }
    void randommerge(Node* head)
    {
        Node* temp=head;
        while(temp )
        {   
            if(temp->random!=NULL)
                temp->next->random  =temp->random->next;
            temp = temp->next->next;
        }
    }
    Node* detach(Node* head)
    {
        Node* dummy = new Node(-1);
        Node* tail = dummy , *temp = head;
        while(temp)
        {
            tail->next = temp->next;
            tail = tail->next;
            temp->next = tail->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        if(head == NULL)return NULL;
       /* Node *temp = head;
        unordered_map<Node* , Node*> m;
        while(temp!= NULL)
        {
            Node *newN = new Node(temp->val);
            m[temp] = newN;
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL )
        { 
             m[temp]->next = m[temp->next];
             m[temp]->random = m[temp->random];
             temp = temp->next;
        }
        return m[head];*/
        copy(head);
        randommerge(head);
        return detach(head);
    }
};