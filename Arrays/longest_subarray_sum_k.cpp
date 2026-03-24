// Problem: Longest Subarray with Sum K
// Platform: LeetCode / GFG
// Pattern: Prefix Sum + HashMap
// Approach:
// 1. Prefix sum calculate karo
// 2. Agar sum == k → length update
// 3. Agar (sum - k) map me hai → subarray exist
// 4. Maximum length track karo
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum == k) {
            maxLen = i + 1;
        }

        if (mp.find(sum - k) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum - k]);
        }

        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return maxLen;
}

// Edge Cases:
// 1. Negative numbers present → sliding window fail
// 2. All elements zero
// 3. No subarray found

// Key Insight:
// Prefix sum repeat hone par beech ka sum = 0
