#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<string,string> pss;
class TrieNode {
    public:
        TrieNode * child[26];
        bool IsEnd;
        TrieNode() {
            for(int i=0;i<26;i++)
                child[i]=NULL;
            IsEnd = false;
        }
};

class Trie {
    private:
        
    public:
        TrieNode * root;
        Trie(){
            root = new TrieNode();
        }
        bool search(string s);
        void insert(string s);
        void dfs(TrieNode*);
        bool isEmpty(TrieNode *);
        vector<string> PreSearch(string);
        TrieNode * deleteKey(TrieNode*, string s, int);
};

TrieNode * Trie::deleteKey(TrieNode * curr, string key, int i) {
    if(curr==NULL) {
        cout<<key<<" Not present in the Trie\n";
        return NULL;
    }
    if(i==key.length()) {
        curr->IsEnd = false;
        if(isEmpty(curr)) {
            delete curr;
            curr = NULL;
            cout<<key<<" has been deleted\n";
        }
        return curr;
    }
    int index = key[i]-'a';
    curr->child[index] = deleteKey(curr->child[index], key, i+1);

    if(isEmpty(curr) && curr->IsEnd==false){
        delete curr;
        curr = NULL;
    }
    return curr;
}

bool Trie::isEmpty(TrieNode * curr) {
    for(int i=0;i<26;i++) {
        if(root->child[i]!=NULL)
            return false;
    }
    return true;
}

void Trie::dfs(TrieNode* curr){
    static string res="";
    char ch = 'a';
    if(curr) {
        if(curr->IsEnd) {
            cout<<res<<endl;
        }
        for(int i=0;i<26;i++)
        {
            if(curr->child[i]){
                res.push_back(char(ch+i));
                dfs(curr->child[i]);
                res.pop_back();
            }
        }
    }
}

void DFSutil(TrieNode * curr, string s, vector<string> &res) {
    static string ext="";
    if(curr) {
        if(curr->IsEnd) {
            res.push_back(s+ext);
        }
        for(int i=0;i<26;i++) {
            if(curr->child[i]) {
                ext.push_back('a'+i);
                DFSutil(curr->child[i], s, res);
                ext.pop_back();
            }
        }
    }
}

vector<string> Trie::PreSearch(string s) {
    //vector<pair<pair<string,string>,int> > s;
    TrieNode * curr = root;
    int flag =0;
    for(auto x : s) {
        if(!curr->child[x-'a']) {
            flag=1;
            break;
        }
        curr = curr->child[x-'a'];
    }
    vector<string> res;
    if(flag==1) {
        cout<<"No strings matched the prefix\n";
        return res;
    }
    
    DFSutil(curr, s, res);
    return res;

}


bool Trie::search(string s) {
    TrieNode * curr = root;
    for(auto x: s){
        if(!curr->child[x-'a'])
            return false;
        curr = curr->child[x-'a'];
    }
    return curr->IsEnd;
}

void Trie::insert(string s) {
    TrieNode * curr = root;
    for(auto x: s){
        if(!curr->child[x-'a'])
            curr->child[x-'a'] = new TrieNode();
        curr = curr->child[x-'a'];
    }
    curr->IsEnd = true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    Trie t;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        t.insert(s);
    }
    t.dfs(t.root);
    cout<<endl;

    // auto x = t.PreSearch("an");
    // for(auto y:x)
    //     cout<<y<<endl;

    t.deleteKey(t.root, "an", 0);
    t.dfs(t.root);
    cout<<endl;
    return 0;
}