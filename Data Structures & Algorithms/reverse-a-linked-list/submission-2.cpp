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
    ListNode* reverseList(ListNode* head) {
        
        std::stack<ListNode*> s; // LIFO
        ListNode* curr = head;
        while(curr) {
            s.push(curr);
            curr = curr->next;
        }

        if (s.empty()) return nullptr;

        ListNode* temp = s.top();
        head = temp;
        s.pop();
        
        while(!s.empty()) {
            temp->next = s.top();
            temp = temp->next;
            s.pop();
        }
        temp->next = nullptr; 

        return head;
    }
};
