/*
Problem: Minimized Maximum of Products Distributed to Any Store
Platform: LeetCode #2064
Difficulty: Medium
Link: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

Pattern: Binary Search on Answer

Approach:
- We need to minimize the maximum number of products assigned to any store (x)
- Each product type can be split across multiple stores
- For a given x:
    - Calculate how many stores are needed using ceil(q / x)
- If required stores <= n → possible → try smaller x
- Else → increase x

Search Space:
- low = 1
- high = max(quantities)

Time: O(n * log(max(quantities)))
Space: O(1)

Key Points:
- Use integer ceil → (q + x - 1) / x
- Avoid floating point (faster + precise)
- Binary search on minimum valid maximum load
*/

class Solution {
public:

    // Check if we can distribute with max x products per store
    bool isPossible(vector<int>& quantities, int n, int x) {
        long long stores = 0;

        for (int q : quantities) {
            // ceil(q / x)
            stores += (q + x - 1) / x;
        }

        return stores <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());

        int ans = high;

        // Binary Search on Answer
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(quantities, n, mid)) {
                ans = mid;
                high = mid - 1;   // try smaller maximum
            } else {
                low = mid + 1;    // increase limit
            }
        }

        return ans;
    }
};
