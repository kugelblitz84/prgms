#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int maximizeFinalElement(vector<int>& arr) {
    // Use a min-heap (priority queue) to always get the two smallest elements efficiently
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    
    while (pq.size() > 1) {
        // Extract the two smallest elements
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        
        // Replace them with their floored average
        int avg = floor((first + second) / 2.0);
        pq.push(avg);
    }
    
    // The last remaining element is the answer
    return pq.top();
}

int main() {
    vector<int> arr = {10, 20, 30, 40}; // Example array
    cout << maximizeFinalElement(arr) << endl;
    return 0;
}
