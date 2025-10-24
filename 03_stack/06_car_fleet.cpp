/*
Problem: Car Fleet

Approach:
- Calculate the time each car takes to reach the target: (target - position[i]) / speed[i].
- Sort cars by starting position in descending order (closest to target first) using a map.
- Use a stack to track fleets:
    - If a car's time to reach the target is less than or equal to the fleet ahead, it joins that fleet.
    - Otherwise, it forms a new fleet.
- The size of the stack at the end is the total number of car fleets.

Complexity:
- Time: O(n log n), due to sorting by position
- Space: O(n), for the stack and map
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Map positions to time to reach target, sorted in descending order of position
        map<int, float, greater<int>> posTime;
        for (int i = 0; i < position.size(); i++) {
            float time = float(target - position[i]) / speed[i];
            posTime[position[i]] = time;
        }

        stack<float> fleets;
        for (auto& p : posTime) {
            if (!fleets.empty() && p.second <= fleets.top()) {
                // Current car joins the fleet ahead
                continue;
            }
            fleets.push(p.second); // New fleet
        }

        return fleets.size();
    }
};
