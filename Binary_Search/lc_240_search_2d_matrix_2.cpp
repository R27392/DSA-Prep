#include <bits/stdc++.h>
using namespace std;

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Problem: Search a 2D Matrix II
Platform: LeetCode #240
Difficulty: Medium
Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
DESCRIPTION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Given an m x n matrix where:
- Each row is sorted in ascending order
- Each column is sorted in ascending order

Return true if target is found, else false.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH (Greedy + Elimination)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- Start from top-right corner
- If current > target → move LEFT
- If current < target → move DOWN
- If equal → return true

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
COMPLEXITY
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Time  : O(m + n)
Space : O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
KEY POINTS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- Each step eliminates one row or one column
- No need for binary search
- Works because row & column are sorted
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
EDGE CASE
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
-single row/colunm
- Empty matrix
-Target out of range
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // Edge case check
        if(matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n - 1; // top-right

        while(i < m && j >= 0) {
            
            if(matrix[i][j] == target) {
                return true;
            }
            else if(matrix[i][j] > target) {
                j--; // move left
            }
            else {
                i++; // move down
            }
        }

        return false;
    }
};
