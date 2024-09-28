#include <iostream>
using namespace std;
class MyCircularDeque {
public:
        int capacity;
        int* data;
        int frontPtr;
        int rearPtr;
        int elemCount;

    MyCircularDeque(int k) {
        capacity = k;
        data = new int[capacity];
        frontPtr = 0;
        rearPtr = 0;
        elemCount = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()){
            return false;
        }
        frontPtr = (frontPtr - 1 + capacity)%capacity;
        data[frontPtr] = value;
        elemCount++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()){
            return false;

        }
        data[rearPtr] = value;
        rearPtr = (rearPtr + 1) % capacity;
        elemCount++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()){
            return false;
        }
        frontPtr = (frontPtr + 1) % capacity;
        elemCount --;
        return true;
    }
    bool deleteLast() {
        if (isEmpty()){
            return false;
        }
        rearPtr = (rearPtr - 1 + capacity)% capacity;
        elemCount --;
        return true;
        
    }
    int getFront() {
        if (isEmpty) return -1;
        return (data[frontPtr]);
        
    }
    
    int getRear() {
        if (isEmpty) return -1;
        return (data[rearPtr]);
        
    }
    
    bool isEmpty() {
        return (elemCount == 0);
    }
    
    bool isFull() {
        return (elemCount == capacity);
    }
};
