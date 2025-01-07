#include <iostream>
#include "LRUCache.h"

int main() {
    std::unordered_map<int, int> map;
    map[9]= 999;
    std::cout<<map[9]<<std::endl;
    std::cout<<map[10]<<std::endl;
    LRUCache<int, std::string> lru_cache(100);
    lru_cache.Put(1, "one");
    std::cout<<lru_cache.Get(1)<<std::endl;
    if(lru_cache.Get(2) == "")
        lru_cache.Put(2, "two");
    std::cout<<lru_cache.Get(2);
    return 0;
}