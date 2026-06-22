#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Twitter
{
private:
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter()
    {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<pair<int, int>> candidates;

        if (tweets.find(userId) != tweets.end())
        {
            const auto &userTweets = tweets[userId];
            int n = userTweets.size();
            for (int i = max(0, n - 10); i < n; i++)
            {
                candidates.push_back(userTweets[i]);
            }
        }

        if (following.find(userId) != following.end())
        {
            for (int followeeId : following[userId])
            {
                if (tweets.find(followeeId) != tweets.end())
                {
                    const auto &followeeTweets = tweets[followeeId];
                    int n = followeeTweets.size();
                    for (int i = max(0, n - 10); i < n; i++)
                    {
                        candidates.push_back(followeeTweets[i]);
                    }
                }
            }
        }

        sort(candidates.begin(), candidates.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first > b.first; });

        vector<int> feed;
        for (int i = 0; i < min(10, (int)candidates.size()); i++)
        {
            feed.push_back(candidates[i].second);
        }

        return feed;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
        {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId)
    {
        if (following.find(followerId) != following.end())
        {
            following[followerId].erase(followeeId);
        }
    }
};

int main()
{
    Twitter twitter;

    cout << "--- Design Twitter Tests ---" << endl;

    twitter.postTweet(1, 5);

    cout << "Feed User 1: [";
    vector<int> f1 = twitter.getNewsFeed(1);
    for (size_t i = 0; i < f1.size(); i++)
        cout << f1[i] << (i < f1.size() - 1 ? ", " : "");
    cout << "]" << endl;

    twitter.follow(1, 2);
    twitter.postTweet(2, 6);

    cout << "Feed User 1 after follow: [";
    vector<int> f2 = twitter.getNewsFeed(1);
    for (size_t i = 0; i < f2.size(); i++)
        cout << f2[i] << (i < f2.size() - 1 ? ", " : "");
    cout << "]" << endl;

    twitter.unfollow(1, 2);

    cout << "Feed User 1 after unfollow: [";
    vector<int> f3 = twitter.getNewsFeed(1);
    for (size_t i = 0; i < f3.size(); i++)
        cout << f3[i] << (i < f3.size() - 1 ? ", " : "");
    cout << "]" << endl;

    return 0;
}