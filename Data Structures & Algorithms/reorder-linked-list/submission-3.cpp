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
    void reorderList(ListNode* head) {

        // get the total count 
        ListNode* currNode = head;
        int count = 0;
        while(currNode){
            count++;
            currNode = currNode->next;
        }

        // get the count of ascending nodes
        int ascend_count = 
            std::floor(static_cast<double>(count) / 2);

        // create the ascending part
        currNode = head;
        for(int i = 1; i <= ascend_count; i++){
            currNode = currNode->next;
        }
        ListNode* temp = currNode->next;
        currNode->next = nullptr;

        // add the temp part to stack
        stack<ListNode*> s;
        while(temp) {
            s.push(temp);
            temp = temp->next;
        }

        currNode = head;
        while(!s.empty()) {
            temp = s.top();
            s.pop();

            ListNode* temp2 = currNode->next;
            currNode->next = temp;
            temp->next = temp2;

            currNode = temp2;
        }
    }
};