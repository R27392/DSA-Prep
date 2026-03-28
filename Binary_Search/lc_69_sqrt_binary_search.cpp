#include <bits/stdc++.h>
using namespace std;

/*
Problem: Sqrt(x)
Platform: LeetCode #69
Difficulty: Easy
Link: https://leetcode.com/problems/sqrtx/

Pattern: Binary Search

Approach:
- Search range [1, x]
- mid*mid <= x → store ans, move right
- else → move left

Time: O(log x)
Space: O(1)

Key Points:
- Use long long to avoid overflow
- Store last valid answer (floor value)
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int low = 1, high = x;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long sq = (long long)mid * mid;

            if (sq <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
