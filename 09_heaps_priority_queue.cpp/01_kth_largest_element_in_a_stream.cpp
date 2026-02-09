/*
Problem: Kth Largest Element in a Stream

Approach:
- Maintain a min-heap of size k to track the k largest elements
- Push each incoming element into the heap
- If heap size exceeds k, remove the smallest element
- The top of the min-heap always represents the kth largest element

Complexity:
- Time: O(log k) per insertion
- Space: O(k), size of the heap
*/

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        // initialize heap with existing numbers
        for (int num : nums) {
            minHeap.push(num);
            // keep only k largest elements
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        // add new value to heap
        minHeap.push(val);
        // remove smallest if size exceeds k
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        // top is the kth largest element
        return minHeap.top();    
    }
};
