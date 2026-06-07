#include <bits/stdc++.h>
using namespace std;

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Problem: Move Zeroes
Platform: LeetCode #283
Difficulty: Easy
Link: https://leetcode.com/problems/move-zeroes/

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
DESCRIPTION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Given an integer array nums, move all 0's to the end
of it while maintaining the relative order of the
non-zero elements.

The operation must be performed in-place.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH (Two Pointer - Fast & Slow Pointer)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- Use two pointers:
    i = position to place next non-zero element
    j = current element

- Traverse array using j
- Whenever a non-zero element is found:
    swap(nums[i], nums[j])
    i++

- After traversal:
    all non-zero elements remain in order
    all zeroes automatically move to the end

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
COMPLEXITY
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Time  : O(n)
Space : O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
KEY POINTS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- In-place solution
- Maintains relative order
- Uses Fast and Slow Pointer technique
- Single traversal

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
LEARNING
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
✓ Fast & Slow Pointer Pattern
✓ In-place Array Modification
✓ Stable Rearrangement
✓ Efficient Element Placement

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
TAGS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#TwoPointers
#Array
#FastSlowPointer
#InPlace
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int i = 0;

        for (int j = 0; j < nums.size(); j++) {

            if (nums[j] != 0) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }
};
