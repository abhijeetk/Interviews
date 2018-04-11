// Correct program and guess output.
// See answer below

#include <iostream>
using namespace std;

class A {
    int x, y;
public:
    A(int x, int y) {
        this->x = x;
        this->y = y;
    }

    virtual void printX() {
        cout << x << endl;
    }

    virtual void printY() {
        cout << y << endl;
    }
};

class B : public A {
public:
    // Add construtor and pass value to Base constructor
    // as it doesn't have default constructor.
    B() : A(0, 0) {

    }
    virtual void printY() {
        cout << 100 << endl;
    }
};

int main() {
    B b;
    b.printX(); // 0
    b.printY(); // 100
}

#if 0
#include <iostream>
using namespace std;

class A {
    int x, y;
public :
    A(int x, int y) {
        this->x = x;
        this->y = y;
    }

    virtual void printX() {
        cout << x << endl;
    }

    virtual void printY() {
        cout << y << endl;
    }
};

class B : public A {
public :
    // Add construtor and pass value to Base constructor
    // as it doesn't have default constructor.
    B() : A(0, 0) {
    
    }
    virtual void printY() {
        cout << 100 << endl;
    }
};

int main() {
    B b;
    b.printX(); // 0
    b.printY(); // 100
}

#endif