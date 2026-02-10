/*
Problem: Design Twitter

Approach:
- Store each user's tweets with a global increasing timestamp
- Maintain follow relationships using a hash map of sets
- Use a max-heap to merge the most recent tweets from followed users
- Always pull the latest tweet and push the next older tweet from the same user

Complexity:
- Time: O(F log F) for news feed, where F is number of followed users
- Space: O(T + F), tweets storage and heap usage
*/

#include <bits/stdc++.h>
using namespace std;

class Twitter {
    int count;
    unordered_map<int, vector<vector<int>>> tweetMap;
    unordered_map<int, set<int>> followMap;

public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // store tweet with timestamp
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        // max-heap based on timestamp
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> minHeap(compare);

        // user follows themselves
        followMap[userId].insert(userId);

        // initialize heap with most recent tweet of each followee
        for (int followeeId : followMap[userId]) {
            if (tweetMap.count(followeeId)) {
                const vector<vector<int>>& tweets = tweetMap[followeeId];
                int index = tweets.size() - 1;
                minHeap.push({tweets[index][0], tweets[index][1], followeeId, index});
            }
        }

        // extract up to 10 most recent tweets
        while (!minHeap.empty() && res.size() < 10) {
            vector<int> curr = minHeap.top();
            minHeap.pop();

            res.push_back(curr[1]);

            int index = curr[3];
            // push next older tweet from same user
            if (index > 0) {
                const vector<int>& tweet = tweetMap[curr[2]][index - 1];
                minHeap.push({tweet[0], tweet[1], curr[2], index - 1});
            }
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        // add follow relationship
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // remove follow relationship
        followMap[followerId].erase(followeeId);
    }   
};
