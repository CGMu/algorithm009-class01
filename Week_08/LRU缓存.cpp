class Node{
public:
    int key;
    int val;
    Node* next;
    Node(){}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        mCacheHead=nullptr;
        mCapacity=capacity;
        mSize=0;
    }
    
    int get(int key) {
        Node *pNode=mCacheHead;
        for(int i=0;i<mSize;i++){
            if(pNode->key==key) return pNode->val;
            pNode=pNode->next;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node *pNewNode=new Node();
        if(!mCacheHead){
            pNewNode->key=key;
            pNewNode->val=value;
            pNewNode->next=nullptr;
            mCacheHead=pNewNode;
            mSize++;
            return;
        }

        Node *preLastNode;
        Node *pNode=mCacheHead;
        for(int i=0;i<mSize;i++){
            if(i==mCapacity-2) preLastNode=pNode;
            if(pNode->key==key) {
                pNode->val=value;
                return;
            }
            pNode=pNode->next;
        }

        pNewNode->key=key;
        pNewNode->val=value;
        pNewNode->next=mCacheHead;
        mCacheHead=pNewNode;
        if(++mSize>mCapacity){
            preLastNode->next=nullptr;
            --mSize;
        }

        return;
    }

private:
    Node* mCacheHead;
    int mCapacity;
    int mSize;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */