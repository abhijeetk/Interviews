/*
    https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
    Hash Table requirement :

    1.  HashNode : A class represents each bucket node in the table
    with key() and value() accessors for corresponding pair elements.
    It also includes a pointer to the next node with same key.

    2. Hash function : ideally assigns each key to a unique bucket,
    but most hash table designs assume that hash collisions can occur.
*/

template <typename K, typename V>
class HashNode {
public:
    HashNode(const K& key, const V& val)
        : key(key),
          val(val),
          next(nullptr){
        cout << "Constructor of HashNode" << endl;
    }

    K getKey() {
        return key;
    }

    V getVal() {
        return val;
    }

    void setVal(V v) {
        val = v;
    }

    HashNode* getNext() {
        return next;
    }

    void setNext(HashNode* n) {
        next = n;
    }
private:
    K key;
    V val;
    HashNode* next;
};

#define TABLE_SIZE 256
template<typename K>
class hashCode {
public:
    unsigned long operator()(const K& key) const {
        return static_cast<unsigned long>(key % TABLE_SIZE);
    }
};

template<typename K, typename V, typename F = hashCode<K>>
class HashMap {
public:
    HashMap() {
        // https://stackoverflow.com/questions/19214038/what-is-the-difference-between-int-a-new-int-and-int-a-new-int
        table = new HashNode<K, V>*[TABLE_SIZE]();
    };

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            HashNode<K, V>* n = table[i];
            while (n) {
                HashNode<K, V>* prev = n;
                n = n->getNext();
                delete prev;
            }
            table[i] = nullptr;
        }
        delete[] table;
    }

    bool get(const K& key, V& val) {
        unsigned long hCode = hash(key);
        HashNode<K, V>* n = table[hCode];
        while (n) {
            if (n->getKey() == key) {
                val = n->getVal();
                return true;
            }
            n = n->getNext();
        }
        return false;
    }

    void put(const K& key, const V& val) {
        unsigned long hCode = hash(key);
        HashNode<K, V>* n = table[hCode];
        HashNode<K, V>* prev = nullptr;
        while (n && n->getKey() != key) {
            prev = n;
            n = n->getNext();
        }

        if (n == nullptr) {
            // key not found
            HashNode<K, V>* newNode = new HashNode<K, V>(key, val);
            if (prev)
                prev->setNext(newNode);
            else
                table[hCode] = newNode; // if n == nullptr && prev == nullptr then its first node;
        }
        else {
            n->setVal(val);
        }
    }

    bool remove(const K& key) {
        unsigned long hCode = hash(key);
        HashNode<K, V>* n = table[hCode];
        HashNode<K, V>* prev = nullptr;
        while (n && n->getKey() != key) {
            prev = n;
            n = n->getNext();
        }

        if (n == nullptr) {
            // not found
            return false;
        }
        else {
            if (prev) {
                prev->setNext(n->getNext());
                delete n;
            }
            else {
                // no previous then its first entry.
                table[hCode] = n->getNext();
                delete n;
            }

        }
    }
private:
    HashNode<K, V> **table;
    F hash;
};

#include <string>
#include <iostream>
using namespace std;

int main() {
    HashMap<int, string> hmap;
    hmap.put(1, "val1");
    hmap.put(2, "val2");
    hmap.put(3, "val3");

    string value;
    hmap.get(2, value);
    cout << value << endl;
    bool res = hmap.get(3, value);
    if (res)
        cout << value << endl;
    hmap.remove(3);
    res = hmap.get(3, value);
    if (res)
        cout << value << endl;
}
