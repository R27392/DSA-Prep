#include <bits/stdc++.h>
using namespace std;

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Problem: Two Sum II - Input Array Is Sorted
Platform: LeetCode #167
Difficulty: Easy
Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
DESCRIPTION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Given a sorted array of integers, find two numbers
such that they add up to a specific target number.

Return 1-based indices of the two numbers.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH (Two Pointer - Opposite Direction)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- Use two pointers: left = 0, right = n-1
- If sum < target → move left++
- If sum > target → move right--
- If equal → return indices

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
COMPLEXITY
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Time  : O(n)
Space : O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
KEY POINTS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- Array is sorted → use two pointer
- Return 1-based indices
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right) {
            int sum = numbers[left] + numbers[right];

            if(sum == target) {
                return {left + 1, right + 1}; // 1-based index
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {}; // no solution
    }
};
