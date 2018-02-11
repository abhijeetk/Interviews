/*
A popular online retailer allows to specify different
prices in advance for the same item throught the day.
We now need ti design an alogorithm that helps identify the lowest
price for the item at any point of the day.

Assumption:
1. For the algorithm, assume all vendors are selling the same product
and there is only one product beign sold. Given a list that has vendor information.
(startTime, endTime, Price) of the deal, return a sorted list with different possible
intervals and the least price of the product during interval.

2. Both start and endtime are inclusive.

3. All three values are positive integers.
*/
#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

class Interval {
public:
    int start;
    int end;
    int value;

    Interval(int s, int e, int v) {
        this->start = s;
        this->end = e;
        this->value = v;
    }
};

bool overlap(Interval* first, Interval* second) {
    if (first->end > second->start || first->start < second->end)
        return true;

    return false;
}

class comparator {
public :
    bool operator() (const Interval* i1, const Interval* i2) const{
        return i1->end < i2->end;
    }
};

void approach2(vector<Interval*>& v) {
    map<pair<int, int>, int> m;
    for (auto vItr : v) {
        for (int i = vItr->start; i < vItr->end; i++) {
            pair<int, int> p = make_pair(i, i + 1);
            auto it = m.find(p);
            if (it != m.end()) {
                int currVal = it->second;
                if (vItr->value < currVal)
                    it->second = vItr->value;
            }
            else {
                m.insert(make_pair(p, vItr->value));
            }

        }
    }

    vector<Interval*> res;
    int currVal = 0;
    for (auto mItr : m) {
        int val = mItr.second;
        if (currVal != val) {
            pair<int, int> p = mItr.first;
            res.push_back(new Interval(p.first, p.second, val));
            currVal = val;
        }
        else {
            res.back()->end = mItr.first.second;
        }
    }

    for (auto i : res) {
        cout << i->start << "," << i->end << ":" << i->value << endl;
    }
    cout << endl;
}
void approach1(vector<Interval*>& v) {
    set<Interval*, comparator> vec;
    for (auto i : v) {
        vec.insert(i);
    }

    auto itr = vec.begin();
    for (auto e = (++vec.begin()); e != vec.end(); e++) {
        Interval *i1 = *itr;
        Interval *i2 = *e;

        if (overlap(i1, i2)) {
            if (i1->value < i2->value)
            {
                i2->start = i1->end;
            }
            else if (i1->value > i2->value) {
                i1->end = i2->start;
            }
            else {
                i1->end = i2->end;
            }

        }
        itr = e;
    }

    for (auto i : vec) {
        cout << i->start << "," << i->end << ":" << i->value << endl;
    }
    cout << endl;
}

int main() {

    Interval* i1 = new Interval(1, 5, 20);
    Interval* i2 = new Interval(3, 8, 15);
    Interval* i3 = new Interval(7, 10, 8);

    vector<Interval*> vec;
    vec.push_back(i1);
    vec.push_back(i2);
    vec.push_back(i3);
    approach1(vec);

    vector<Interval*> vec2;
    vec2.push_back(i2);
    vec2.push_back(i1);
    vec2.push_back(i3);
    approach2(vec2);

    return 0;
}