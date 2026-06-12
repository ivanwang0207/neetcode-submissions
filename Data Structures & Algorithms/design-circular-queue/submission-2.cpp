class MyCircularQueue {

private:
    std::vector<int> buffer_;
    int capacity_ = 0; // max size of buffer
    int size_ = 0; // current count of elements
    int front_ = 0;
    int rear_ = 0;

public:
    MyCircularQueue(int k): capacity_(k), buffer_(k) {
    }
    
    bool enQueue(int value) {
        if (size_ == capacity_) { return 0; }
        buffer_[rear_] = value;
        rear_ = (rear_ + 1) % capacity_;
        size_++;
        return 1;
    }
    
    bool deQueue() {
        if (size_ == 0) { return 0; }
        front_ = (front_ + 1) % capacity_;
        size_--;
        return 1;
    }
    
    int Front() {
        return size_ != 0 ? buffer_[front_] : -1;
    }
    
    int Rear() {
        if (size_ == 0) return -1;
        return buffer_[(rear_ - 1 + capacity_) % capacity_];
    }
    
    bool isEmpty() {
        return size_ == 0;
    }
    
    bool isFull() {
        return size_ == capacity_;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */