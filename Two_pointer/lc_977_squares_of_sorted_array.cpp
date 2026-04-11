#include <bits/stdc++.h>
using namespace std;

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Problem: Squares of a Sorted Array
Platform: LeetCode #977
Difficulty: Easy
Link: https://leetcode.com/problems/squares-of-a-sorted-array/

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
DESCRIPTION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Given a sorted integer array (can contain negative numbers),
return an array of the squares of each number sorted in non-decreasing order.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH (Two Pointer - Opposite Direction)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- Use two pointers: left = 0, right = n-1
- Compare absolute values
- Place larger square at the end of result array

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
COMPLEXITY
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Time  : O(n)
Space : O(n)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
KEY POINTS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- Negative numbers can give larger squares
- Fill result array from the end
- Use absolute value comparison
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n);

        int left = 0;
        int right = n - 1;
        int idx = n - 1;

        while(left <= right) {
            
            if(abs(nums[left]) > abs(nums[right])) {
                ans[idx] = nums[left] * nums[left];
                left++;
            } else {
                ans[idx] = nums[right] * nums[right];
                right--;
            }

            idx--;
        }

        return ans;
    }
};
