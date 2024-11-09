#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val){
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int capacity;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node){

        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAtHead(Node* node){

        Node* curr = head->next;
        node->next = curr;
        curr->prev = node;
        head->next = node;
        node->prev = head;
    }
    
    int get(int key) {
        
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            int res = node->val;
            deleteNode(node);
            insertAtHead(node);
            return res;    
        }

        return -1;

        
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insertAtHead(node);
            return;
        }
        if(mp.size()==capacity){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        insertAtHead(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

