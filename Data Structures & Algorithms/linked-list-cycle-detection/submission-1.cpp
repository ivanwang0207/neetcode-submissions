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
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return 0;

        ListNode* p = head->next;
        ListNode* q = head->next->next;

        while(p != q){

            if (!q || !q->next)
                return 0;
            
            p = p->next;
            q = q->next->next;
        }

        return 1;
    }
};
