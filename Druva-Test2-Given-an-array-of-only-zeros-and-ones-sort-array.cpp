#include <iostream>
using namespace std;

void sortArray(int* arr, int left, int right) {
    if (left = 1 && right == 1)
        return;

    while(left < right) {

        while (arr[left] == 0 && left < right) {
            left++;
        }

        while (arr[right] == 1 && left < right) {
            right--;
        }
        // swap
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    } // End of while
}

void display(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    int arr1[]= { 0, 1, 0, 1 };
    int size = sizeof(arr1) / sizeof(int);
    sortArray(arr1, 0, size - 1);
    display(arr1, size);

    int arr2[] = { 0, 1};
    size = sizeof(arr2) / sizeof(int);
    sortArray(arr2, 0, size - 1);
    display(arr2, size);

    int arr3[] = { 1 };
    size = sizeof(arr3) / sizeof(int);
    sortArray(arr3, 0, size - 1);
    display(arr3, size);

    int arr4[] = { 1, 1, 1, 1 };
    size = sizeof(arr4) / sizeof(int);
    sortArray(arr4, 0, size - 1);
    display(arr4, size);

    int arr5[] = { 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };
    size = sizeof(arr5) / sizeof(int);
    sortArray(arr5, 0, size - 1);
    display(arr5, size);

    return 0;
}