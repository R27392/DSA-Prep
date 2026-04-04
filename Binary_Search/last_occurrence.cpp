// Problem: Last Occurrence in Sorted Array
// Pattern: Binary Search upper & lower bound
// Approach:
// 1. target मिलते ही ans update करो
// 2. right side जाओ (last index चाहिए)
// Time: O(log n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;
            low = mid + 1;   // right move
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
