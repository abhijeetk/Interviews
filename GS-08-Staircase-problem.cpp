#include <iostream>
#include<vector>

using namespace std;

int countNumberOfSteps(int n) {
    if (n == 0 || n == 1)
        return 1;

    vector<int> count(n+1, 0);
    count[0] = 1;
    count[1] = 1;
    for (int i = 2; i<=n; i++)
    {
        count[i] = 0;
        count[i] = count[i] + (i - 1 < 0 ? 0 : count[i - 1]);
        count[i] = count[i] + (i - 2 < 0 ? 0 : count[i - 2]);
        count[i] = count[i] + (i - 3 < 0 ? 0 : count[i - 3]);
    }
    return count[n];
}

int main() {
    cout << countNumberOfSteps(0) << endl;
    cout << countNumberOfSteps(1) << endl;
    cout << countNumberOfSteps(2) << endl;
    cout << countNumberOfSteps(3) << endl;
    cout << countNumberOfSteps(7) << endl;
    return 0;
}
