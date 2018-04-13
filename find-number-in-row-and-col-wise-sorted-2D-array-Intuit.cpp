#include <iostream>
#include <functional>

using namespace std;

int main() {
    const int ROW = 3;
    const int COL = 4;
    int arr[ROW][COL] = {
        1,  4,  7,  9,
        5,  6,  8,  12,
        12, 13, 14, 15
    };

    int x;
    cout << "Number to find ? " << endl;
    cin >> x;

    // Compare number with top-right corner,
    // arr[top][right] is greatest number in a row(top).
    // if x > arr[top][right] it means x is greater than all element in row
    // so go to next row -> i++
    // arr[top][right] is smallest  number in a coloum(right).
    // if x < arr[top][right] it means x is smaller than all element in coloum
    // so go to previous coloum -> j--

    int i = 0;
    int j = COL-1;
    bool found = false;
    while (j >= 0 && i < ROW) {
        if (arr[i][j] == x) {
            found = true;
            break;
        }

        if (x > arr[i][j]) {
            i++;
        }
        else {
            j--;
        }
    }

    if (found)
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    return 0;
}