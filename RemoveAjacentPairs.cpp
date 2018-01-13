/*
    Author : Abhijeet Kandalkar
    LinkedIn : https://www.linkedin.com/in/abhijeetkandalkar/
*/

#include "iostream"
using namespace std;

void removeAdjacentPairs(char* s) {
    int i, j;
    j = 0; // copy pointer
    for (i = 1; i < strlen(s); i++) {
        while (s[i] == s[j] && j >= 0 && i < strlen(s)) {
            i++;
            j--;
        }

        j++;
        s[j] = s[i];
    }
    s[++j] = '\0';
}

int main() {
    char str[] = "ABCCBCBA";
    removeAdjacentPairs(str);
    cout << str << endl;

    char str1[] = "ABBBCCCCBBBAbbmaabbX";
    removeAdjacentPairs(str1);
    cout << str1 << endl;

    return 0;
}