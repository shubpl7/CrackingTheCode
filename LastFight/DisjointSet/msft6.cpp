//last jump
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
vector<bool> vis;
bool DFS(int idx, vector<int> &arr) {
    if(idx<0 || idx>=arr.size())
        return false;
    if(vis[idx])
        return false;
    vis[idx] = true;
    if(arr[idx]==0)
        return true;
    return DFS(idx-arr[idx], arr) || DFS(idx+arr[idx], arr);
    
} 
bool jump_game(vector<int> arr, int start) {
    // WRITE YOUR BRILLIANT CODE HERE
    int n = arr.size();
    vis.resize(n, false);
    return DFS(start, arr);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    int n, start;
    cin>>n>>start;
    vector<int> arr(n);
    for(auto & x: arr)
        cin>>x;
    cout<<jump_game(arr, start);
    return 0;
}