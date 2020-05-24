class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        mFront=0;
        mLast=0;
        mSize=0;
        mCapacity=k;
        mArray=new int[k];
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        if(--mFront<0) mFront=mCapacity-1;
        mArray[mFront]=value;
        mSize++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        mArray[mLast++]=value;
        if(mLast==mCapacity) mLast=0;
        mSize++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        if(++mFront==mCapacity) mFront=0;
        mSize--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        if(--mLast<0) mLast=mCapacity-1;
        mSize--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty()?-1:mArray[mFront];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) return -1;
        int index = mLast-1;
        if (index < 0) index = mCapacity - 1;
        return mArray[index];
        // return isEmpty()?-1:mArray[mLast];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return mSize==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return mSize==mCapacity;
    }

    private:
        int* mArray;
        int mFront;
        int mLast;
        int mSize;
        int mCapacity;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */