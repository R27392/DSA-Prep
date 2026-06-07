#include <bits/stdc++.h>
using namespace std;

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Problem: Two Sum
Platform: LeetCode #1
Difficulty: Easy
Link: https://leetcode.com/problems/two-sum/

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
DESCRIPTION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up
to target.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH (Two Pointer)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- Sort the array
- Use two pointers:
    left = 0
    right = n - 1
- Calculate current sum
- If sum == target, return indices
- If sum < target, move left pointer
- If sum > target, move right pointer

Note:
This approach works for finding a pair sum in a sorted array.
For LeetCode Two Sum, sorting changes original indices,
therefore HashMap approach is preferred.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
COMPLEXITY
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Time  : O(n log n)
Space : O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
KEY POINTS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- Uses opposite-direction two pointers
- Requires sorted array
- Not suitable for original LeetCode Two Sum indices

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
LEARNING
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
✓ Two Pointer Pattern
✓ Opposite Direction Traversal
✓ Pair Sum in Sorted Array
✓ Limitation of Sorting when original indices are needed

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
TAGS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#TwoPointers
#Array
#Sorting
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = n - 1;

        while (left < right) {

            int sum = nums[left] + nums[right];

            if (sum == tar) {
                return {left, right};
            }
            else if (sum < tar) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};
