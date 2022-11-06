#include<bits/stdc++.h>
class MyHashMap {
public:
    int store[1000001];
    MyHashMap() {
        fill(store, store+1000001, -1);
    }
    
    void put(int key, int value) {
        store[key] = value;
        
    }
    
    int get(int key) {
        return store[key];
    }
    
    void remove(int key) {
        store[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
