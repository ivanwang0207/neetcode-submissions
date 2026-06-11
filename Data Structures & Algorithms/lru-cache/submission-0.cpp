class Node{
public:
    Node(int key, int value): key(key), value(value), next(nullptr), prev(nullptr) {}

    int key, value;
    Node *next, *prev;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        rear = nullptr;
    }
    
    int get(int key) {
        // get the node from the map
        if (map.find(key) == map.end())
            return -1;

        Node* p = map[key];
        moveToHead(p);
        return head->value;
    }
    
    void put(int key, int value) {

        // If key already exists, update its value and move it to head
        if (map.find(key) != map.end()) {
            Node* existingNode = map[key];
            existingNode->value = value;  // Update value
            moveToHead(existingNode);      // Move it to head
            return;
        }

        // create new node and point head to it
        Node* p = new Node(key, value);
        map[key] = p;

        // Add new node to head
        if (!head) {  // If cache is empty
            head = rear = p;
        } else {
            p->next = head;
            head->prev = p;
            head = p;
        }

        // Check capacity
        if (map.size() > capacity) {
            removeLRU();
        }
    }

private:
    unordered_map<int, Node*> map;
    Node* head; // the most recent one
    Node* rear; // the least recent one
    int capacity;

    void moveToHead(Node* p) {
        // if p is just right the head node
        if (p == head) 
            return;

        // Remove node from its current position 
        if(p->prev)
            p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;

        // if its the case of rear node
        if (p == rear){
            rear = rear->prev;
            rear->next = nullptr;
        } 

        // Move node to head
        p->next = head;
        p->prev = nullptr;
        head->prev = p;
        head = p;
    }

    void removeLRU() {
        // if (!rear) return;  // Nothing to remove

        // Remove from map and delete rear node
        map.erase(rear->key);
        
        Node* temp = rear;

        if (rear->prev) {
            rear = rear->prev;
            rear->next = nullptr;  // Update next pointer of new rear
        } 

        delete temp;  // Free memory of removed node
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */