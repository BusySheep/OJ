#include <cstdio>
#include <list>
#include <map>
using namespace std;

class LRUCache{
private:
    list< pair<int, int> > cacheData;
    map<int, list<pair<int, int> >::iterator> cacheMap;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cacheMap.count(key) > 0) {
            int result = (*cacheMap[key]).second;
            cacheData.erase(cacheMap[key]);
            cacheData.push_front(make_pair(key, result));
            cacheMap[key] = cacheData.begin();
            return result;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (get(key) != -1) {
            (*cacheData.begin()).second = value;
        } else {
            if (cacheData.size() == capacity) {
                int victimKey = (*cacheData.rbegin()).first;
                cacheData.pop_back();
                cacheMap.erase(victimKey);
            }
            cacheData.push_front(make_pair(key, value));
            cacheMap[key] = cacheData.begin();
        }
    }
};

int main() {
    int capacity;
    printf("input capacity: ");
    scanf("%d", &capacity);
    LRUCache cache(capacity);
    while (true) {
        int choice;
        printf("input choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int key, value;
            printf("input key and value: ");
            scanf("%d %d", &key, &value);
            cache.set(key, value);
        } else {
            int key;
            printf("input key: ");
            scanf("%d", &key);
            printf("get: %d\n", cache.get(key));
        }
    }
    return 0;
}