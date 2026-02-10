/*
Problem: Find Median from Data Stream

Approach:
- Use two heaps: max-heap for lower half, min-heap for upper half
- Insert numbers into appropriate heap based on comparison
- Rebalance heaps so size difference is at most one
- Median is top of max-heap (odd count) or average of both tops (even count)

Complexity:
- Time: O(log n) per insertion, O(1) for median retrieval
- Space: O(n), storing all elements in heaps
*/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    int count = 0;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        count++;

        // insert into appropriate heap
        if (maxH.empty() || num <= maxH.top())
            maxH.push(num);
        else
            minH.push(num);

        // rebalance heaps if needed
        if (maxH.size() > minH.size() + 1) {
            int temp = maxH.top();
            maxH.pop();
            minH.push(temp);
        }

        if (minH.size() > maxH.size()) {
            int temp = minH.top();
            minH.pop();
            maxH.push(temp);
        }
    }
    
    double findMedian() {
        double median = 0;

        // even number of elements
        if (count % 2 == 0) {
            median = (double)(maxH.top() + minH.top()) / 2;
        }
        // odd number of elements
        else 
            median = maxH.top();

        return median;
    }
};
