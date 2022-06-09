#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
VVI mat;
int m, n;
struct TrieNode{
    TrieNode *child[2];
    TrieNode(){
        child[0]= child[1] = NULL;
    }
};
bool insert(TrieNode * root, int rowIdx) {
    bool flag = false;
    TrieNode * curr = root;
    for(int i=0;i<n;i++) {
        if(!curr->child[mat[rowIdx][i]]){
            curr->child[mat[rowIdx][i]] = new TrieNode();
            flag = true;
        }
        curr = curr->child[mat[rowIdx][i]];
    }
    return flag;
}

int countDistinct(TrieNode * root){
    int res=0;
    for(int i=0;i<m;i++) {
        if(insert(root, i))
            res++;
    }
    return res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    VVI v{ {1,0,0}, 
            {1,1,1}, 
            {1,0,0}, 
            {0,1,0}
        };
    mat = v;
    m = mat.size();
    n = mat[0].size();
    TrieNode * root = new TrieNode();
    cout<<countDistinct(root);
    return 0;
}