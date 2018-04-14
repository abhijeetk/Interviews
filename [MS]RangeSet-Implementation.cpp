/*
    Design a RangeSet class where you can Add, Delete and search in a optimized way
    References :
    https://www.codeproject.com/Articles/10308/RangeSet-A-Low-Memory-Set-Data-Structure-for-Integ
*/

#include <iostream>
#include <vector>
using namespace std;

class IRangeSet {
private:
    int low_;
    int high_;
public:
    IRangeSet(int low, int high) : low_(low), high_(high) {
    }

    int low() { return low_; }
    int high() { return high_; }
    bool contain(int element) {
        return (element >= low_ && element <= high_);
    }
};

class RangeSet {
    vector<IRangeSet*> set;
public:
    RangeSet() {}
    void add(IRangeSet *r) {
        set.push_back(r);
    }

    void remove(IRangeSet *r) {
        for (auto itr = set.begin(); itr != set.end(); itr++) {
            if ((*itr)->low() == r->low() && (*itr)->high() == r->high()) {
                set.erase(itr);
            }
        }
    }

    IRangeSet* find(int element) {
        if (set.empty()) {
            return nullptr;
        }

        int low = 0;
        int high = set.size() - 1;
        while (low <= high)
        {
            int middle = (low == high) ? low : ((low + high) / 2);
            IRangeSet *curRange = set.at(middle);

            if (curRange->contain(element))
            {
                return set[middle];
            }
            else if (curRange->low() > element)
            {
                high = middle - 1;
            }
            else if (curRange->high() < element)
            {
                low = middle + 1;
            }
            else
            {
                return nullptr;
            }
        }

        // Standard data structures hack to indicate
        // the appropriate insertion point as a part of this call.
        return set[low + 1];
    }
};

int main() {
    RangeSet r;
    r.add(new IRangeSet(1, 9));
    r.add(new IRangeSet(10, 19));
    r.add(new IRangeSet(20, 29));
    r.add(new IRangeSet(30, 39));
    r.add(new IRangeSet(40, 49));

    IRangeSet *rs = r.find(31);
    cout << "31.\t" << rs->low() << " : " << rs->high() << endl;
    rs = r.find(1);
    cout << "1.\t" << rs->low() << " : " << rs->high() << endl;
    rs = r.find(21);
    cout << "21.\t" << rs->low() << " : " << rs->high() << endl;
    return 0;
}