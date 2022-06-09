#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int n, k;
vector<int> hospital;
vector<vector<int> > adj;
int BFS() {
    vector<int> dis(n+1,INT_MAX);
    queue<int> q;
    for(auto x:hospital){
        q.push(x);
        dis[x] = 0;
    }
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto neigh: adj[curr]) {
            if(dis[neigh]>dis[curr]+1){
                dis[neigh] = dis[curr] +1;
                q.push(neigh);
            }
        }
    }
    int maxDis = INT_MIN;
    for(int i=1;i<=n;i++) {
        maxDis = max(maxDis, dis[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
    return maxDis;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    cin>>n>>k;
    hospital.resize(k);
    adj.resize(n+1);
    for(auto &x: hospital)
        cin>>x;
    int noOfEdges;
    cin>>noOfEdges;
    for(int i=0;i<noOfEdges;i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<BFS()<<endl;
    return 0;
}