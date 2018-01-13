/*
    Author : Abhijeet Kandalkar
    LinkedIn : https://www.linkedin.com/in/abhijeetkandalkar/
*/
#include <iostream>
using namespace std;

bool patternMatching(char* text, char* pattern) {
    if (*text == '\0' && *pattern == '\0')
        return true;

    if (*pattern == '*' && *(pattern + 1) != '\0' && *text == '\0')
        return false;

    // pattern : "ge?ks*" text : "geeksforgeeks"
    if (*pattern == '*' && *(pattern + 1) == '\0' && *text == '\0')
        return true;

    if (*pattern == '?' || *pattern == *text)
        return patternMatching(text + 1, pattern + 1);

    if (*pattern == '*')
        return (patternMatching(text + 1, pattern) ||
            patternMatching(text, pattern + 1));

    return false;
}

void test(char *first, char *second)
{
    patternMatching(second, first) ? puts("Yes") : puts("No");
}

int main() {
    test("g*ks", "geeks"); // Yes
    test("ge?ks*", "geeksforgeeks"); // Yes
    test("g*k", "gee");  // No because 'k' is not in second
    test("*pqrs", "pqrst"); // No because 't' is not in first
    test("abc*bcd", "abcdhghgbcd"); // Yes
    test("abc*c?d", "abcd"); // No because second must have 2
                             // instances of 'c'
    test("*c*d", "abcd"); // Yes
    test("*?c*d", "abcd"); // Yes

    return 0;
}
