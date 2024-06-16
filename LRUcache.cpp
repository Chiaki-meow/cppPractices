// LRU cache in C++
// hash map + double link list
// reference: https://hawstein.com/2013/07/23/lru-cache-impl/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template<class K, class T>
struct Node {
    K key;
    T data;
    Node *prev, *next;
};

template<class K, class T>
class LRUCache {
private:
    unordered_map<K, Node<K, T> *> hashmap;
    vector<Node<K, T> *> free_entries;
    Node<K, T> *head, *tail;
    Node<K, T> *entries;
private:
    void detach(Node<K, T> *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void attach(Node<K, T> *node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

public:
    LRUCache(size_t size) {
        entries = new Node<K, T>[size];
        for (int i = 0; i < size; i++)
            free_entries.push_back(entries + i);
        head = new Node<K, T>, tail = new Node<K, T>;
        head->prev = nullptr;
        tail->next = nullptr;
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        delete head;
        delete tail;
        delete[] entries;
    }

    void Put(K key, T data) {
        Node<K, T> *node = hashmap[key];
        if (node) {
            detach(node);
            node->data = data;
            attach(node);
        }
        else {
            if(free_entries.empty()){
                // cache已满，清除掉最近最少使用的entry
                node = tail->prev;
                detach(node);
                hashmap.erase(node->key);
            }
            else{
                node = free_entries.back();
                free_entries.pop_back();
            }
            node->key = key;
            node->data = data;
            hashmap[key] = node;
            attach(node);
        }
    }
    T Get(K key){
        Node<K, T> *node = hashmap[key];
        if(node){
            detach(node);
            attach(node);
            return node->data;
        }
        else{
            return T();
        }
    }
    };

    int main() {
        unordered_map<int, int> map;
        map[9]= 999;
        cout<<map[9]<<endl;
        cout<<map[10]<<endl;
        LRUCache<int, string> lru_cache(100);
        lru_cache.Put(1, "one");
        cout<<lru_cache.Get(1)<<endl;
        if(lru_cache.Get(2) == "")
            lru_cache.Put(2, "two");
        cout<<lru_cache.Get(2);
        return 0;
    }