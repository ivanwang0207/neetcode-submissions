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
        // obtain the total count 
        ListNode* p = head;
        int count = 0;
        while(p) {
            count++;
            p = p->next;
        }

        ListNode* r;
        p = head;
        if (count - n == 0) 
            return p->next;

        for(int i = 0; i < count - n; i++){
            r = p;
            p = p->next;
        }
        r->next = p->next;
        delete p;  
        return head;
    }
};
