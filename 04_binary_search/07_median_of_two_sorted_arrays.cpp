/*
Problem: Median of Two Sorted Arrays

Approach:
- Use binary search on the smaller array to partition both arrays into two halves:
    - Left half contains smaller elements
    - Right half contains larger elements
- At each partition, check if all elements on the left are ≤ all elements on the right.
- If valid partition:
    - If total length is odd → median is min(right elements)
    - If even → median is average of max(left) and min(right)
- Else, adjust binary search boundaries accordingly.

Complexity:
- Time: O(log(min(n, m))), where n and m are lengths of the arrays
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure binary search on the smaller array
        vector<int> A = nums1, B = nums2;
        if (B.size() < A.size()) swap(A, B);

        int total = A.size() + B.size();
        int half = total / 2;

        int l = 0, r = (int)A.size() - 1;

        while (true) {
            int i = floor((l + r) / 2.0);
            int j = half - i - 2;

            double Aleft  = (i >= 0) ? A[i] : -INFINITY;
            double Aright = (i + 1 < (int)A.size()) ? A[i + 1] : INFINITY;
            double Bleft  = (j >= 0) ? B[j] : -INFINITY;
            double Bright = (j + 1 < (int)B.size()) ? B[j + 1] : INFINITY;

            // Valid partition found
            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 == 1)
                    return min(Aright, Bright);
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }

            // Adjust binary search
            else if (Aleft > Bright)
                r = i - 1;
            else
                l = i + 1;
        }
    }
};

