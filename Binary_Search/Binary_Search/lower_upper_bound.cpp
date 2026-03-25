// Problem: Lower Bound & Upper Bound
// Pattern: Binary Search
// Approach:
// Lower Bound = first index where element >= target
// Upper Bound = first index where element > target
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

// Lower Bound
int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();  // default (not found)

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1; // left side
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Upper Bound
int upperBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target) {
            ans = mid;
            high = mid - 1; // left side
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Lower Bound:
// First position jahan value >= target

// Upper Bound:
// First position jahan value > target

// Use Cases:
// 1. First occurrence
// 2. Last occurrence
// 3. Count of elements

count = upperBound(arr, x) - lowerBound(arr, x);
