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

void insert(TrieNode * root, int x, int idx) {
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
        curr->val = idx;
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
int getMaxXORSubarray(vector<int> & nos, int n) {
    
    TrieNode * root = new TrieNode();
    int ans = 0;
    int prefixXor[n+1];
    prefixXor[0] = 0;
    for( int i=1;i<=n;i++) {
        prefixXor[i] = prefixXor[i-1] ^ nos[i];
    }
    insert(root, 0, 0);
    for(int i=1;i<=n;i++) {
        auto resp = computeXor(prefixXor[i], root);
        insert(root, prefixXor[i], i);
        if(resp.first>ans) {
            ans = resp.first;
            cout<<ans<<" = "<<" xor of elements from index "<<resp.second+1<<" till "<<i<<endl;
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
    vector<int> nos; nos.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>nos[i];
    cout<<getMaxXORSubarray(nos, n);
    return 0;
}