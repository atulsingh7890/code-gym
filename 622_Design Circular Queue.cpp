//#include <vector>
//#include <cassert>
//#include <iostream>
//
//class MyCircularQueue {
//public:
//    /** Initialize your data structure here. Set the size of the queue to be k. */
//    MyCircularQueue(int k) {
//        underlying_container_.resize(k+1);
//    }
//
//    /** Insert an element into the circular queue. Return true if the operation is successful. */
//    bool enQueue(int value) {      
//		bool result = false;
//		if (!isFull()) {
//			underlying_container_[back_] = value;
//			back_ = (back_ + 1) % underlying_container_.size();
//			result = true;
//		}
//		return result;
//    }
//
//    /** Delete an element from the circular queue. Return true if the operation is successful. */
//    bool deQueue() {
//		bool result = false;
//		if (!isEmpty()) {			
//			front_ = (front_ + 1) % underlying_container_.size();
//			result = true;
//		}
//		return result;
//    }
//
//    /** Get the front item from the queue. */
//    int Front() {
//        int front = -1;
//        if (!isEmpty())
//            front =  underlying_container_[front_];
//        return front;
//    }
//
//    /** Get the last item from the queue. */
//    int Rear() {
//		int back = -1;
//        if (!isEmpty()) {
//
//            back = underlying_container_[back_ > 0 ? back_ - 1 : underlying_container_.size() - 1];
//        }            
//		return back;
//    }
//
//    /** Checks whether the circular queue is empty or not. */
//    bool isEmpty() {
//        return front_ == back_;
//    }
//
//    /** Checks whether the circular queue is full or not. */
//    bool isFull() {
//        int index_prev_front = front_ > 0 ? front_ - 1 : underlying_container_.size() - 1;
//        return index_prev_front  == back_;
//    }
//private:
//    std::vector<int> underlying_container_;        
//    int front_ = 0;
//    int back_ = 0;
//};
//
///**
// * Your MyCircularQueue object will be instantiated and called as such:
// * MyCircularQueue* obj = new MyCircularQueue(k);
// * bool param_1 = obj->enQueue(value);
// * bool param_2 = obj->deQueue();
// * int param_3 = obj->Front();
// * int param_4 = obj->Rear();
// * bool param_5 = obj->isEmpty();
// * bool param_6 = obj->isFull();
// */
//int main() {
//    MyCircularQueue circular_queue(4);
//    assert(true == circular_queue.isEmpty());
//    assert(false == circular_queue.isFull());
//    assert(true == circular_queue.enQueue(1));
//    assert(false == circular_queue.isEmpty());
//    assert(false == circular_queue.isFull());
//    assert(true == circular_queue.enQueue(2));
//    assert(true == circular_queue.enQueue(3));
//    assert(true == circular_queue.enQueue(4));
//	assert(false == circular_queue.isEmpty());
//	assert(true == circular_queue.isFull());
//    assert(false == circular_queue.enQueue(4));
//    assert(true == circular_queue.deQueue());
//    assert(true == circular_queue.enQueue(5));
//    assert(true == circular_queue.deQueue());
//    assert(true == circular_queue.deQueue());
//    assert(true == circular_queue.enQueue(6));
//    assert(true == circular_queue.enQueue(7));
//}