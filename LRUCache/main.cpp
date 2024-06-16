#include <iostream>
#include "LRUCache.h"

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