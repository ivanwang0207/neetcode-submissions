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
        ListNode* p = head;
        if (!p || !p->next) return 0;
        ListNode* q = p->next->next;

        while(p != q){

            if (!q || !q->next)
                return 0;
            
            p = p->next;
            q = q->next->next;
        }

        return 1;
    }
};
