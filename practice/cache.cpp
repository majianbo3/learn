#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

// 定义 LRU 缓存类
class LRUCache {
private:
    int capacity;  // 缓存容量
    list<int> keys;  // 双向链表存储键，用于维护访问顺序
    unordered_map<int, pair<int, list<int>::iterator>> cache;  // 哈希表存储键值对及对应的链表迭代器

public:
    // 构造函数，初始化缓存容量
    LRUCache(int capacity) : capacity(capacity) {}

    // 获取缓存中键对应的值
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;  // 如果键不存在，返回 -1
        }
        // 更新访问顺序，将该键移动到链表头部
        keys.erase(it->second.second);
        keys.push_front(key);
        it->second.second = keys.begin();
        return it->second.first;  // 返回键对应的值
    }

    // 插入或更新缓存中的键值对
    void put(int key, int value) {
        if (cache.size() >= capacity && cache.find(key) == cache.end()) {
            // 如果缓存已满且键不存在，淘汰最不常用的键（链表尾部的键）
            auto last = keys.back();
            cache.erase(cache.find(last));
            keys.pop_back();
        }
        // 插入或更新键值对，并更新访问顺序
        cache[key] = { value, keys.insert(keys.begin(), key) };
    }
};

int main() {
    // 创建一个容量为 2 的 LRU 缓存
    LRUCache cache(2);

    // 插入键值对 (1, 1)
    cache.put(1, 11);
    // 访问键 1，输出其值
    cout << "get(1) = " << cache.get(1) << endl; // 返回 1

    // 插入键值对 (2, 2)
    cache.put(2, 22);
    // 访问键 2，输出其值
    cout << "get(2) = " << cache.get(2) << endl; // 返回 2

    // 插入键值对 (3, 3)，由于缓存已满，键 1 被淘汰
    cache.put(3, 33);
    // 访问键 1，由于已被淘汰，返回 -1
    cout << "get(1) = " << cache.get(1) << endl; // 返回 -1
    // 访问键 3，输出其值
    cout << "get(3) = " << cache.get(3) << endl; // 返回 3

    // 插入键值对 (4, 4)，由于缓存已满，键 2 被淘汰
    cache.put(4, 44);
    // 访问键 1，由于已被淘汰，返回 -1
    cout << "get(1) = " << cache.get(1) << endl; // 返回 -1
    // 访问键 3，输出其值
    cout << "get(3) = " << cache.get(3) << endl; // 返回 -1
    // 访问键 2，由于已被淘汰，返回 -1
    cout << "get(2) = " << cache.get(2) << endl; // 返回 -1
    // 访问键 4，输出其值
    cout << "get(4) = " << cache.get(4) << endl; // 返回 4

    return 0;
}