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
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return nullptr;

        // craete a table that maps the old node to the new
        unordered_map<Node*, Node*> map;
        map[nullptr] = nullptr; // the nullptr case

        // tackle the first node
        Node* p = head; // old head
        Node* newNode = new Node(p->val); // new head

        Node* tp_old = head;
        Node* tp_new = newNode;

        map[p] = newNode;
        tp_old = tp_old->next;

        while(tp_old) {
            Node* temp = new Node(tp_old->val); // new
            map[tp_old] = temp;
            tp_new->next = temp;

            tp_old = tp_old->next;
            tp_new = tp_new->next;

        }

        tp_old = head;
        tp_new = newNode; 
        while(tp_new) {
            tp_new->random = map[tp_old->random];
            tp_old = tp_old->next;
            tp_new = tp_new->next;
        }
        return newNode;
    }
};