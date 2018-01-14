/*
    https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/

*/
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int startOfTour(vector<petrolPump>& arr) {
    int n = arr.size();
    int start = 0;
    int end = 1;
    int curr_petrol = arr[start].petrol - arr[start].distance;
    // Add at 'end' and remove from 'start'
    // start != end checks circular queue
    while (start != end || curr_petrol < 0) {

        while (start != end && curr_petrol < 0) {
            // Remove and then increament 'start'
            curr_petrol = curr_petrol - (arr[start].petrol - arr[start].distance);
            start = (start + 1) % n;

            if (start == 0)
                return -1;
        }
        // Add and then increament 'end'
        curr_petrol = curr_petrol + (arr[end].petrol - arr[end].distance);
        end = (end + 1) % n;
    }
    return start;
}

int main() {
    vector<petrolPump> arr = { { 6, 4 },{ 3, 6 },{ 7, 3 } };
    cout << startOfTour(arr) << endl;
    return 0;
}