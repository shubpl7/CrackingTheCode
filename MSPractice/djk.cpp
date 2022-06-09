// dijikstra algorithm


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
class graph{
    public:
        int edges;
        int vertices;
        graph(){}
        graph(int e, int v) {
            edges=e;vertices=v;
            adj.resize(v);
            dis.resize(v,INT_MAX);
            parent.resize(v,-1);
        }
        vector<vector<pair<int,int> > > adj;
        vector<int> dis;
        vector<int> parent;
        void addEdge(int u, int v,int wt);
        void dijikstra(int src);

};
void graph::addEdge(int u, int v, int wt) {
    adj[u].PB(make_pair(v,wt));
    adj[v].PB(make_pair(u,wt));
}
void graph::dijikstra(int src) {
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    pq.push(make_pair(0,src));
    parent[src]=-1;
    dis[src]=0;
    while(!pq.empty()) {
        auto x = pq.top();
        int u = x.second;
        pq.pop();
        for(auto y:adj[u]) {
            int v = y.first;
            int wt = y.second;
            if(dis[v]>dis[u]+wt) {
                dis[v] = dis[u]+wt;
                parent[v]=u;
                pq.push(make_pair(dis[v],v));
            }
        }
    }
    for(int i=0;i<vertices;i++) {
        cout<<"Shortest dis. of vertex: "<<i<<" from the src: "<<src<<" is: "<<dis[i]<<" and the route path is: \n";
        vector<int> res;
        int j=i;
        while(j!=-1) {
            res.PB(j);
            j = parent[j];
        }
        reverse(res.begin(), res.end());
        for(auto x: res) {
            cout<<x;
            if(x!=*(res.rbegin()))
                cout<<"---->";
        }
        cout<<endl;
        res.clear();
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int v,e;
    cin>>v>>e;
    graph g(e,v);
    for(int i=0;i<e;i++) {
        int a, b, wt;
        cin>>a>>b>>wt;
        g.addEdge(a,b,wt);
    }
    g.dijikstra(0);
    return 0;
}