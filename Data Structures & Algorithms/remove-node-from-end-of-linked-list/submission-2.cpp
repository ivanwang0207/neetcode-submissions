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

        // get the index of node that we want to remove 
        int count = 0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;
            count++;
        }

        // remove header pointer
        if (count - n == 0) {
            temp = head;
            head = head->next;
            delete temp;

            return head;
        }

        // navigate to the one need to be removed
        ListNode* curr = head;
        ListNode* prev;
        for(int i = 0; i < count - n; ++i) {
            prev = curr;
            curr = curr->next;
        }

        // remove the curr pointer
        prev->next = curr->next;
        delete curr;

        return head;
    }
};
