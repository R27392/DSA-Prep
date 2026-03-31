#include <bits/stdc++.h>
using namespace std;

/*
Problem: Minimum Number of Days to Make m Bouquets
Platform: LeetCode #1482
Difficulty: Medium
Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

Pattern: Binary Search on Answer

Approach:
- We need to find minimum day such that we can make m bouquets
- Each bouquet requires k adjacent flowers

- Search space = [min(arr), max(arr)]
- For each mid (day):
    → Check if possible to make m bouquets

- If possible → try smaller day (left)
- Else → increase day (right)

Time: O(n log n) // O(n log maxday) 
Space: O(1)

Key Points:
- Use greedy check inside possible()
- Count consecutive flowers ≤ day
- Reset count when condition breaks
*/

class Solution {
public:

    bool possible(vector<int>& arr, int day, int m, int k) {
        int cnt = 0;      // consecutive flowers
        int bouquets = 0; // number of bouquets formed

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) {
                cnt++;
            } else {
                bouquets += (cnt / k);
                cnt = 0;
            }
        }

        bouquets += (cnt / k);

        return bouquets >= m;
    }

    int minDays(vector<int>& arr, int m, int k) {
        long long need = 1LL * m * k;
        if (need > arr.size()) return -1;

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(arr, mid, m, k)) {
                high = mid - 1;  // try smaller day
            } else {
                low = mid + 1;   // need more days
            }
        }

        return low;
    }
};
