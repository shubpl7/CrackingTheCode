#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
struct TrieNode{
    TrieNode *child[26];
    bool isEnd;
    int count;
    TrieNode(){
        for(int i=0;i<26;i++)
            child[i] = NULL;
        isEnd = false;
        count=0;
    }
};

void insert(TrieNode * root, string &key) {
    TrieNode * curr = root;
    for(auto &ch : key) {
        if(!curr->child[ch-'a']) {
            curr->child[ch-'a'] = new TrieNode();
        }
        curr = curr->child[ch-'a'];
        curr->count++;
    }
    curr->isEnd = true;
}

string getUnique(TrieNode * root, string & key) {
    string ans;
    TrieNode * curr = root;
    for(auto ch: key) {
        ans += ch;
        curr = curr->child[ch-'a'];
        if(curr->count==1)
            return ans;
    }
    return "-1";
}

vector<string> UniquePrefixArray(vector<string> & words, int n) {
    TrieNode * root = new TrieNode();
    for(auto word: words) {
        insert(root, word);
    }
    vector<string> ans;
    for(auto word: words) {
        ans.push_back(getUnique(root, word));
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    vector<string> words;
    int n;
    cin>>n;
    words.resize(n);
    for(auto &x: words)
        cin>>x;
    vector<string> ans = UniquePrefixArray(words, n);
    for(auto x: ans)
        cout<<x<<" ";
    return 0;
}