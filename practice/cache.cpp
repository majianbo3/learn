#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

// ���� LRU ������
class LRUCache {
private:
    int capacity;  // ��������
    list<int> keys;  // ˫������洢��������ά������˳��
    unordered_map<int, pair<int, list<int>::iterator>> cache;  // ��ϣ��洢��ֵ�Լ���Ӧ�����������

public:
    // ���캯������ʼ����������
    LRUCache(int capacity) : capacity(capacity) {}

    // ��ȡ�����м���Ӧ��ֵ
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;  // ����������ڣ����� -1
        }
        // ���·���˳�򣬽��ü��ƶ�������ͷ��
        keys.erase(it->second.second);
        keys.push_front(key);
        it->second.second = keys.begin();
        return it->second.first;  // ���ؼ���Ӧ��ֵ
    }

    // �������»����еļ�ֵ��
    void put(int key, int value) {
        if (cache.size() >= capacity && cache.find(key) == cache.end()) {
            // ������������Ҽ������ڣ���̭����õļ�������β���ļ���
            auto last = keys.back();
            cache.erase(cache.find(last));
            keys.pop_back();
        }
        // �������¼�ֵ�ԣ������·���˳��
        cache[key] = { value, keys.insert(keys.begin(), key) };
    }
};

int main() {
    // ����һ������Ϊ 2 �� LRU ����
    LRUCache cache(2);

    // �����ֵ�� (1, 1)
    cache.put(1, 11);
    // ���ʼ� 1�������ֵ
    cout << "get(1) = " << cache.get(1) << endl; // ���� 1

    // �����ֵ�� (2, 2)
    cache.put(2, 22);
    // ���ʼ� 2�������ֵ
    cout << "get(2) = " << cache.get(2) << endl; // ���� 2

    // �����ֵ�� (3, 3)�����ڻ����������� 1 ����̭
    cache.put(3, 33);
    // ���ʼ� 1�������ѱ���̭������ -1
    cout << "get(1) = " << cache.get(1) << endl; // ���� -1
    // ���ʼ� 3�������ֵ
    cout << "get(3) = " << cache.get(3) << endl; // ���� 3

    // �����ֵ�� (4, 4)�����ڻ����������� 2 ����̭
    cache.put(4, 44);
    // ���ʼ� 1�������ѱ���̭������ -1
    cout << "get(1) = " << cache.get(1) << endl; // ���� -1
    // ���ʼ� 3�������ֵ
    cout << "get(3) = " << cache.get(3) << endl; // ���� -1
    // ���ʼ� 2�������ѱ���̭������ -1
    cout << "get(2) = " << cache.get(2) << endl; // ���� -1
    // ���ʼ� 4�������ֵ
    cout << "get(4) = " << cache.get(4) << endl; // ���� 4

    return 0;
}