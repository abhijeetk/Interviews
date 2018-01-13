/*
    Author : Abhijeet Kandalkar
    LinkedIn : https://www.linkedin.com/in/abhijeetkandalkar/
*/
#include <iostream>
using namespace std;

void permutation(int depth, char perm[], int used[], char origional[]) {
    int len = strlen(origional);
    if (depth == len)
        cout << perm << endl;
    else {
        for (int i = 0; i < len; i++) {
            if (!used[i]) {
                used[i] = 1;
                perm[depth] = origional[i];
                permutation(depth+1, perm, used, origional);
                used[i] = 0;
            }
        }
    }
}

int main() {
    char* s = "ABC";
    int len = strlen(s);
    char perm[3]; //(char*)malloc(sizeof(char)*len);
    memset(perm, 0, sizeof(char)*len);
    int used[3]; //(int*)malloc(sizeof(int)*len);
    memset(used, 0, sizeof(int)*len);
    permutation(0, perm, used, s);
    return 0;
}
