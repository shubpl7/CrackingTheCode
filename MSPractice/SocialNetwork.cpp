#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;



class User {
    public:
    string userID,userName,description;
    int noOFPosts,noOfFollowers,noOfFollowing;
    User(){}
    User(string userId,string userName,string desc)
    {
        this->userID = userId;
        this->userName = userName;
        this->description = desc;
        noOFPosts=0;noOfFollowers=0;noOfFollowing=0;
    }
};

class Post {
    public:
        string postId, postContents;
        int timestamp;
        Post(){};
        Post(string id, string cont, int currTime) {
            postId = id;postContents = cont;timestamp = currTime;
        }
};

bool onTime(Post a, Post b) {
    return a.timestamp<b.timestamp;
}

class SocialNetwork{
    public:
        map<string, vector<string> > network;
        map<string, vector<Post>> PostsMap;
        map<string, vector<string> > LikedPosts;
        map<string, User> UserDetails;
        map<string, Post> PostDetails;
        void RegisterUser(string, string, string);
        void FollowUser(string, string);
        void unFollowUser(string, string);
        void createPost(string, string, string, int);
        void getFeed(string);
        void getAllUserInfo();
        void likePost(string, string);
        void getAllLikedPosts(string);

};
void SocialNetwork::likePost(string uid, string pid) {
    LikedPosts[uid].push_back(pid);
}

void SocialNetwork::getAllLikedPosts(string userId) {
    for(auto x: LikedPosts[userId]) {
        cout<<PostDetails[x].postId<<"   "<<PostDetails[x].postContents<<endl;
    }
}

void SocialNetwork::getAllUserInfo() {
    for(auto x:UserDetails)
    {
        cout<<"UserId: "<<x.first<<"  "<<"name: "<<x.second.userName<<"  "<<" description: "<<x.second.description<<" posts: "<<PostsMap[x.first].size()<<" followers: "<<x.second.noOfFollowers<<" following:"<<x.second.noOfFollowing<<endl;

    }
}

void SocialNetwork::getFeed(string userId) {
    if(UserDetails.find(userId)==UserDetails.end()) {
        cout<<"userId NOT exist!\n";
        return;
    }
    vector<Post> FeedPosts;
    for(auto following:network[userId]) {
        for(auto posts: PostsMap[following]) {
            FeedPosts.push_back(posts);
        }
    }

    sort(FeedPosts.begin(), FeedPosts.end(), onTime);
    for(auto x: FeedPosts) {
        cout<<x.postId<<" ---> "<<x.postContents<<" ---> "<<x.timestamp<<endl;
    }

}

void SocialNetwork::createPost(string creatorUserId, string postId, string Contents, int currTime) {
    if(PostDetails.find(postId)!=PostDetails.end()) {
        cout<<postId<<" already exixts\n";
        return;
    }
    
    Post p(postId, Contents, currTime);
    PostDetails[postId] = p;
    PostsMap[creatorUserId].push_back(p);
    cout<<"Post "<<postId<<" created!\n";

}

void SocialNetwork::unFollowUser(string followerUserId, string followingUserId) {
    if(UserDetails.find(followerUserId)==UserDetails.end()) {
        cout<<"followerUserId does not exist!\n";
        return;
    }
    auto it = find(network[followerUserId].begin(),network[followerUserId].end(),followingUserId);
    if(it==network[followerUserId].end()){
        cout<<followerUserId<<" already DO NOT follows "<<followingUserId<<endl;
        return;
    }
    network[followerUserId].erase(it);
    UserDetails[followerUserId].noOfFollowing--;
    UserDetails[followingUserId].noOfFollowers--;
}

void SocialNetwork::FollowUser(string followerUserId, string followingUserId) {
    if(UserDetails.find(followerUserId)==UserDetails.end()) {
        cout<<"followerUserId does not exist!\n";
        return;
    }
    auto it = find(network[followerUserId].begin(),network[followerUserId].end(),followingUserId);
    if(it!=network[followerUserId].end()){
        cout<<followerUserId<<" already follows "<<followingUserId<<endl;
        return;
    }
    network[followerUserId].push_back(followingUserId);
    UserDetails[followerUserId].noOfFollowing++;
    UserDetails[followingUserId].noOfFollowers++;
}

void SocialNetwork::RegisterUser(string userId, string userName, string desc) {
    if(UserDetails.find(userId)!=UserDetails.end()) {
        cout<<"userId has already been taken!\n";
        return;
    }
    User u(userId,userName,desc);
    UserDetails[userId] = u;
    cout<<userName<<" is registered successfully!\n";
}



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    SocialNetwork s;
    s.RegisterUser("shub", "shubham", "I am a coder");
    s.RegisterUser("avni","Avani", "Hi, I love books");
    s.RegisterUser("gvr", "Gaurav", "My name is Gaurav");
    s.FollowUser("shub","avni");
    s.FollowUser("shub", "gvr");
    s.createPost("avni","p1","avani started her schooling", 1);
    s.createPost("gvr", "p2", "gaurav started his schooling", 2);
    s.getFeed("shub");
    return 0;
}