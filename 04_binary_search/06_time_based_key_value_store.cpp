/*
Problem: Time-Based Key-Value Store (TimeMap)

Approach:
- Use an unordered_map to store each key with a vector of (timestamp, value) pairs.
- For `set`, simply append the (timestamp, value) pair to the vector.
- For `get`, perform binary search on the vector to find the largest timestamp <= given timestamp:
    - Initialize maxPossible = -1.
    - Use binary search to find the rightmost timestamp ≤ target timestamp.
    - If found, return corresponding value; otherwise, return empty string.

Complexity:
- Time:
    - set: O(1)
    - get: O(log n), where n = number of entries for the key
- Space: O(n), for storing all entries
*/

#include <bits/stdc++.h>
using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> map;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        map[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto &values = map[key];
        if (values.empty()) return "";

        int l = 0, r = values.size() - 1;
        int maxPossible = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (values[mid].first <= timestamp) {
                maxPossible = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (maxPossible == -1) return "";
        return values[maxPossible].second;
    }
};
