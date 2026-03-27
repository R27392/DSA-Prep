// Problem: First Occurrence in Sorted Array
// Pattern: Binary Search
// Goal: Find the FIRST index where arr[i] == target

// Approach:
// 1. Use Binary Search
// 2. When target is found, store index
// 3. Move LEFT to find earlier occurrence
// 4. Continue until search space 

// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;
            high = mid - 1;  // move LEFT
        }
        else if (arr[mid] < target) {
            low = mid + 1;   // move RIGHT
        }
        else {
            high = mid - 1;  // move LEFT
        }
    }

    return ans;
}
