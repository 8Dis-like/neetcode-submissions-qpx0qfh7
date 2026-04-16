class Twitter {
    int time;
    unordered_map<int,unordered_set<int>>followmp;
    unordered_map<int,vector<pair<int,int>>>tweetmp;
public:
    Twitter():time(0){ }
    
    void postTweet(int userId, int tweetId) {
        tweetmp[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>>feed=tweetmp[userId];
        for(int followeeid:followmp[userId]){
            feed.insert(feed.end(), tweetmp[followeeid].begin(),tweetmp[followeeid].end());
        }sort(feed.begin(),feed.end(),[](auto&a,auto&b){return a.first>b.first;});
        vector<int>res;
        for(int i=0;i<min(10,(int)feed.size());i++)res.push_back(feed[i].second);
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)followmp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmp[followerId].erase(followeeId);
    }
};
