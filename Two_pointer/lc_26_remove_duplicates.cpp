#include <bits/stdc++.h>
using namespace std;

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Problem: Remove Duplicates from Sorted Array
Platform: LeetCode #26
Difficulty: Easy
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
DESCRIPTION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Given a sorted integer array nums, remove the duplicates
in-place such that each unique element appears only once.

Return the number of unique elements.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH (Two Pointer - Fast & Slow Pointer)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- Since the array is already sorted,
  duplicates will appear consecutively.

- Use two pointers:
    i = last unique element index
    j = current element index

- Traverse array using j
- Whenever nums[j] != nums[i]:
    increment i
    place nums[j] at nums[i]

- After traversal:
    indices [0...i] contain all unique elements

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
COMPLEXITY
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Time  : O(n)
Space : O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
KEY POINTS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- Array must be sorted
- In-place modification
- Single traversal
- Uses Fast & Slow Pointer technique

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
LEARNING
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
✓ Fast & Slow Pointer Pattern
✓ In-place Array Processing
✓ Sorted Array Property
✓ Duplicate Removal Technique

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
TAGS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#TwoPointers
#Array
#FastSlowPointer
#SortedArray
#InPlace
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0;

        for (int j = 1; j < nums.size(); j++) {

            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};
