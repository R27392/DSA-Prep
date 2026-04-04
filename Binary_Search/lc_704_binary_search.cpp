// Problem: Binary Search
// Platform: LeetCode (704)
// Pattern: Binary Search
// Approach:
// 1. Search space = [0, n-1]
// 2. mid calculate (overflow safe)
// 3. target compare → left / right move
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }
};

// Edge Cases:
// 1. Empty array
// 2. Target not present → return -1
// 3. Single element array

// Key Insight:
// Always use: mid = low + (high - low) / 2
// Avoid overflow from (low + high)/2

// Brute Force:
// Linear search → O(n)

// Optimal:
// Binary Search → O(log n)
