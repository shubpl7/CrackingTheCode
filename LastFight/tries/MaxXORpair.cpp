#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
struct TrieNode{
    TrieNode * child[2];
    int val;
    TrieNode(){
        child[0] = child[1] = NULL;
        val = -1;
    }
};

void insert(TrieNode * root, int x) {
    TrieNode * curr = root;
    for(int j=31;j>=0;j--) {
            if((1<<j) & x){
                if(!curr->child[1]){
                    curr->child[1] = new TrieNode();
                }
                curr = curr->child[1];
            }
            else
            {
                if(!curr->child[0]){
                    curr->child[0] = new TrieNode();
                }
                curr = curr->child[0];
            }
        }
        curr->val = x;
}

pair<int,int> computeXor(int x, TrieNode * root) {
    TrieNode * curr = root;
    int ans = 0;
    for(int j=31;j>=0;j--) {
        if((1<<j & x)) {
            //curr bit is set, lookup for unset bit
            if(curr->child[0]){
                curr = curr->child[0];
                ans += (1<<j);
            }
            else if(curr->child[1]){
                curr = curr->child[1];
            }
        }
        else
        {
            //curr bit is unset, lookup for set bit
            if(curr->child[1]){
                curr = curr->child[1];
                ans += (1<<j);
            }
            else if(curr->child[0]){
                curr = curr->child[0];
            }
        }
    }
    return {ans, curr->val};

}
int getMaxXORpair(vector<int> & nos, int n) {
    
    TrieNode * root = new TrieNode();
    int ans = 0;
    for(auto x: nos) {
        auto resp = computeXor(x, root);
        insert(root, x);
        if(resp.first>ans) {
            ans = resp.first;
            cout<<ans<<" = "<<x<<" xor "<<resp.second<<endl;
        }
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
    int n;
    cin>>n;
    vector<int> nos; nos.resize(n);
    for(auto & x: nos)
        cin>>x;
    cout<<getMaxXORpair(nos, n);
    return 0;
}