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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p;
        ListNode* head;
        int t = 0;

        // estimate the sum of the first nodes
        int s = l1->val + l2->val;
        t = floor(static_cast<double>(s) / 10); // tens digit
        ListNode* node = new ListNode(s - t * 10); // units digit
        p = node;
        head = node;

        l1 = l1->next;
        l2 = l2->next;

        while(l1 || l2){
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            s = t + val1 + val2;
            t = floor(static_cast<double>(s) / 10); // tens digit
            node = new ListNode(s - t * 10); // units digit

            p->next = node;
            p = p->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;;
        }
        if (t > 0){
            node = new ListNode(t); // units digit
            p->next = node;
        }

        return head;
    }
};
