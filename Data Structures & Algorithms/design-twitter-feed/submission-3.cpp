class Twitter {
public:
    int time = 0;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> following;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        if(tweets.find(userId) != tweets.end()){
            for(auto it:tweets[userId]){
                pq.push({it.first,it.second});
            }
        }

        if(following.find(userId) != following.end()){
            for(auto it:following[userId]){
                if(tweets.find(it) != tweets.end()){
                    for(auto tweet:tweets[it]){
                        pq.push({tweet.first,tweet.second});
                    }
                }
            }
        }

        vector<int> ans;
        int i = 0 ;
        while(i < 10 && !pq.empty()){
            auto [time,tweet] = pq.top();
            pq.pop();
            ans.push_back(tweet);
            i++;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
    if (followerId != followeeId) {
        following[followerId].insert(followeeId);
    }
}
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
