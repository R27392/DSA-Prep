// Problem: Search Insert Position
// Platform: LeetCode (35)
// Pattern: Binary Search (Lower Bound)
// Approach:
// Find first index where element >= target
// If target not present, return insertion position
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = nums.size(); // default position

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;  // left move
            } else {
                low = mid + 1;   // right move
            }
        }

        return ans;
    }
};

// Dry Run:
// nums = [1,3,5,6], target = 2
// mid = 1 → nums[mid] = 3 ≥ 2 → move left
// ans = 1
