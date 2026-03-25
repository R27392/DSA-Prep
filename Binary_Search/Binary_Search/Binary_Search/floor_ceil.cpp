// Problem: Floor and Ceil in Sorted Array
// Pattern: Binary Search  && upper & lower bound concept
// Time: O(log n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

// Floor (largest ≤ x)
int findFloor(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x) {
            ans = arr[mid];
            low = mid + 1;  // right move
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// Ceil (smallest ≥ x)
int findCeil(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = arr[mid];
            high = mid - 1;  // left move
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
