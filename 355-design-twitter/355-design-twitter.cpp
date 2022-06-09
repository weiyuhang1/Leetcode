class Twitter {
public:
    //assume most recent tweetId is larger
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        
        publishtime.push_back(tweetId);   //index of tweetId automaticcaly equalls time stamp;
        newsfeed[userId].push(timestamp);  //update newsfeed for himeself
        if (newsfeed[userId].size() > 10) newsfeed[userId].pop();
        
        //update for other followers
        for (int followerid : followers[userId]) {
            newsfeed[followerid].push(timestamp);
            if (newsfeed[followerid].size() > 10) newsfeed[followerid].pop();
        }
        
        selftweets[userId].push(timestamp);
        if (selftweets[userId].size() > 10) selftweets[userId].pop();
        timestamp++;
        
    }
    
    vector<int> getNewsFeed(int userId) {   //could work, tweets starts from an empty database
        vector<int> feed;
        // if size <= 10 needs to create a new newsfeed, otherwise just update
        priority_queue<int, vector<int>, greater<int>> tmp = newsfeed[userId];  //otherwise delete the 10 items in newsfeed for the user after the request
        while (!tmp.empty()) {
            feed.push_back(tmp.top());
            tmp.pop();
        }
        sort(feed.begin(), feed.end());
        for (int i = feed.size() - 1; i >= 0; i--) {
            feed[i] = publishtime[feed[i]];
        }
        reverse(feed.begin(), feed.end());
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if ((followees[followerId]).find(followeeId) != followees[followerId].end()) return;
        followees[followerId].insert(followeeId);
        followers[followeeId].insert(followerId);
        //update 10 tweets from the most recent followeeId for newsfeed
       queue<int> tweets= selftweets[followeeId];
        while (!tweets.empty()) {
            newsfeed[followerId].push(tweets.front());
            tweets.pop();
            if (newsfeed[followerId].size() > 10) newsfeed[followerId].pop();
        }
        
        
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
        followers[followeeId].erase(followerId);
        //recalculating newsfeed since followee unsubscribed
        while (!newsfeed[followerId].empty()) newsfeed[followerId].pop();
      
        for (int followee : followees[followerId]) {
            queue<int> tweets = selftweets[followee];
            while (!tweets.empty()) {
                newsfeed[followerId].push(tweets.front());
                tweets.pop();
                if (newsfeed[followerId].size() > 10) newsfeed[followerId].pop();
            }   
        }
         queue<int> tweets = selftweets[followerId];
            while (!tweets.empty()) {
                newsfeed[followerId].push(tweets.front());
                tweets.pop();
                if (newsfeed[followerId].size() > 10) newsfeed[followerId].pop();
            }   
        
        
        
    }

private:
    unordered_map<int, unordered_set<int>> followees;  //map followerId to all the followeeId list
    unordered_map<int, unordered_set<int>> followers; 
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> newsfeed;  //use storage to trade off traversal the whole subscription list every time
    unordered_map<int, queue<int>> selftweets;  //store the most recent 10 tweets for the user himself
     vector<int> publishtime;
    int timestamp;
    
    
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */