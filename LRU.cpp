/*
    Author : Abhijeet Kandalkar
    LinkedIn : https://www.linkedin.com/in/abhijeetkandalkar/
*/
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
    list<int> pages;
    unordered_map<int, list<int>::iterator > map;
    unsigned int size;
public:
    LRUCache(int csize) : size(csize), map() {
    }

    void referPage(int page) {
        // When a page is referenced, the required page may be in the memory.
        // If it is in the memory, we need to detach the node of the list and
        // bring it to the front of the queue.
        auto itr = map.find(page);
        if (itr != map.end()) {
            list<int>::iterator pItr = itr->second;
            pages.erase(pItr);
            map.erase(page);
        }
        // If the required page is not in the memory, we bring that in memory.
        // In simple words, we add a new node to the front of the queue and
        // update the corresponding node address in the hash.
        // If the queue is full, i.e.all the frames are full, we remove a node
        // from the rear of queue, and add the new node to the front of queue.
        else {
            if (pages.size() == size) {   // queue is full
                int last = pages.back();
                pages.pop_back();
                map.erase(last);
            }
        }
        pages.push_front(page);
        map.insert(make_pair(page, pages.begin()));
    }

    void display() {
        cout << endl;
        for (int i : pages) {
            cout << i << "\t";
        }
    }

};

int main() {
    LRUCache cache(4);

    cache.referPage(1);
    cache.referPage(2);
    cache.referPage(3);
    cache.referPage(1);
    cache.referPage(4);
    cache.referPage(5);
    cache.display();

    return 0;
}