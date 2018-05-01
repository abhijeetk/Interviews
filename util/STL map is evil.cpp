#include <iostream>
#include <map>
#include <algorithm>
#include <memory> // unique_ptr
using namespace std;

int main() {

    // 1. INSERTION 
    map<char, int> mymap;
    mymap.insert(pair<char, int>('a', 100));
    mymap.insert(pair<char, int>('z', 200));
    auto ret = mymap.insert(std::pair<char, int>('z', 500));
    if (ret.second == false) {
        /*
        Because element keys in a map are unique, the insertion operation checks
        whether each inserted element has a key equivalent to the one of an element
        already in the container, and if so, the element is not inserted,
        returning an iterator to this existing element (if the function returns a value).
        */
        cout << "element 'z' already existed";
        cout << " with a value of " << ret.first->second << '\n';
    }
    cout << "Size of map : " << mymap.size() << endl;

    map<char, int> mymap2;
    mymap2['a'] = 100;
    mymap2['z'] = 200;
    for(auto it : mymap2) {
        cout << "[" << it.first << ", " << it.second << "]" << endl;
    }
    // Insert doesn;t allow to modify value at already existed key but [] operator does.
    mymap2['z'] = 500;
    for (auto it : mymap2) {
        cout << "[" << it.first << ", " << it.second << "]" << endl;
    }


    cout << "____ INSERTION and memory leaks ____" << endl;
    // 2. INSERTION and memory leaks because of pointer
    // https://stackoverflow.com/questions/1594631/stdmap-difference-between-index-and-insert-calls
    std::map< int, std::string* > intMap;
    std::string* s1 = new std::string;
    std::string* s2 = new std::string;
    intMap.insert(std::make_pair(100, s1)); // inserted.
    intMap.insert(std::make_pair(100, s2)); // fails, s2 not in map, 
                                            // could leak if not released manualy 
    auto itr = intMap.insert(std::make_pair(100, s2));
    if (itr.second == false) {
        cout << "Key already exist. s2 is not inserted. Release memory here " << endl;
        delete s2;
    }

    std::map< int, std::string* > intMap2;
    std::string* s21 = new std::string("Hi");
    std::string* s22 = new std::string("Hello");
    intMap2[100] = s21; // inserted
    intMap2[100] = s22; // inserted, s21 now dropped from map, could leak if not released
    intMap2.clear();    // Just to check whether clearing map will destruct strings or not
    cout << s21->data() << endl;
    cout << s22->data() << endl;
    delete s21;

    // To avoid memory leaks, use smart pointers instead of raw pointers
    // https://stackoverflow.com/questions/8800770/stl-map-operator-bad
    map<char, unique_ptr<string>> mapToPointers;
    mapToPointers.emplace('a', std::make_unique<string>("I am A"));
    mapToPointers['b'] = std::unique_ptr<string>(new string("I am B"));
    mapToPointers['b'] = std::unique_ptr<string>(new string("I am C"));
    // Here memory allocated to "I am B" will get destroyed once it goes out of scope.
    mapToPointers.clear();

    // Best wat to insert element in map 
    // if key does not exist => it == std::end(m)
    // or 
    // if it already exist => m.key_comp()(3, it->first)
    // Find a value and create it if it doesn't exist:
    // This code is just like internal implementation of insert() API
    // but it provide you more control on actual insertion operation
    std::map<int, std::unique_ptr<int>> m;
    m.insert(pair<int, std::unique_ptr<int>>(3, std::unique_ptr<int>(new int(3))));
    auto it = m.lower_bound(3);
    if (it == std::end(m) || m.key_comp()(3, it->first))
        it = m.insert(it, std::make_pair(3, std::unique_ptr<int>(new int(33)))); // Find a value and create it if it doesn't exist:


    std::map<int, std::unique_ptr<int>> m1;
    auto& obj = m1[3]; // value is default constructed if it doesn't exists.
    if (!obj) {
        try {
            obj = std::unique_ptr<int>(new int(3)); // default constructed value is overwritten.
        } catch (...) {
            m1.erase(3);
            throw;
        }
    }


    // 3. Map in if statement
    /*
    https://stackoverflow.com/questions/8800770/stl-map-operator-bad
    map[i] = new someClass; // potential dangling pointer when executed twice
        Or
    if (map[i]==NULL) // implicitly create the entry i in the map 
    */
    std::map<char, int> myArr;
    myArr.insert(pair<char, int>('a', 1));  // class template need parameter type during call
    myArr.insert(make_pair('b', 2));  // fucntion template deduce parameter type
    myArr['c'] = 3;
    if (myArr['c'] != NULL)
        cout << "value associated with c is " << myArr['c'] << endl;

    cout << "Size of map : " << myArr.size() << endl; // Size of map : 3

    /*
    mapped_type& operator[] (const key_type& k);

    If k matches the key of an element in the container, the function returns a reference
    to its mapped value.

    If k does not match the key of any element in the container, the function inserts
    a new element with that key and returns a reference to its mapped value.
    Notice that this always increases the container size by one, even if no mapped
    value is assigned to the element (the element is constructed using
    its default constructor).
    */
    if (myArr['d'] != NULL)  // because of this statement d is added to map
        cout << "value associated with d is " << myArr['c'] << endl;

    cout << "Size of map : " << myArr.size() << endl; // Size of map : 4

    auto o = myArr['k']; // value is default constructed if it doesn't exists.
    cout << "Size of map : " << myArr.size() << endl; // Size of map : 5

    // Best way to search in map
    if (myArr.find('e') == myArr.end()) {
        cout << "e does not exist" << endl;
    }

    if (myArr.find('d') == myArr.end()) {
        cout << "d does not exist" << endl;
    }



    return 0;

}