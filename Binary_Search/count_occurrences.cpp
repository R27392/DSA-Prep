// Problem: Count Occurrences in Sorted Array
// Pattern: Binary Search
// Idea: count = lastIndex - firstIndex + 1
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

// First Occurrence
int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;
            high = mid - 1; // left
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

// Last Occurrence
int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;
            low = mid + 1; // right
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

// Count function
int countOccurrences(vector<int>& arr, int target) {
    int first = firstOccurrence(arr, target);

    if (first == -1) return 0; // not present

    int last = lastOccurrence(arr, target);

    return last - first + 1;
}
