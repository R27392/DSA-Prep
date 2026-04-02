/*
Problem: Find the Smallest Divisor Given a Threshold
Platform: LeetCode #1283
Difficulty: Medium
Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

Pattern: Binary Search on Answer

Approach:
- We need to find the smallest divisor such that:
    sum(ceil(nums[i] / divisor)) <= threshold

- Search range:
    low = 1
    high = max(nums)

- For each mid (divisor):
    - Calculate sum using ceil division
    - If sum <= threshold → possible → try smaller divisor
    - Else → increase divisor

Time: O(n * log(max(nums)))
Space: O(1)

Key Points:
- Use ceil division → (num + div - 1) / div
- Avoid floating point (better precision & faster)
- Binary search on minimum valid divisor
*/

class Solution {
public:

    // Helper function to compute sum of divisions
    int computeSum(vector<int>& nums, int div) {
        int sum = 0;

        for (int num : nums) {
            // ceil(num / div) without floating point
            sum += (num + div - 1) / div;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        // Binary Search on Answer
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (computeSum(nums, mid) <= threshold) {
                high = mid - 1;   // try smaller divisor
            } else {
                low = mid + 1;    // need larger divisor
            }
        }

        return low;
    }
};
