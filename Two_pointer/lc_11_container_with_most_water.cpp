#include <bits/stdc++.h>
using namespace std;
/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Problem: Container With Most Water
Platform: LeetCode #11
Difficulty: Medium
Link: https://leetcode.com/problems/container-with-most-water/

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
DESCRIPTION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Given an array of heights, find two lines that together
form a container such that the container holds the maximum amount of water.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH (Two Pointer - Opposite Direction)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- Use two pointers: left = 0, right = n-1
- Area = min(height[left], height[right]) * (right - left)
- Move the pointer with smaller height

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
COMPLEXITY
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Time  : O(n)
Space : O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
KEY POINTS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
- Width decreases every step
- Only moving smaller height can improve area
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while(left < right) {
            
            int h = min(height[left], height[right]);
            int width = right - left;
            int area = h * width;

            maxWater = max(maxWater, area);

            // Move smaller height
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};
