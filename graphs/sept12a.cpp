#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
class graph{
    public:
        int Vertices;
        int edges;
        vector<bool> virus;
        vector<vector<int> > adj;
        graph(int v)
        {
            this->Vertices = v;
            adj.resize(v+1);
            virus.resize(v+1,false);
        }
        void addEdge(int a,int b)
        {
            adj[a].PB(b);
            adj[b].PB(a);
        }
        int minTimeForSpreadingVirus(vector<int>& initial)
        {
            queue<pair<int,int> > q;
            for(auto x: initial)
            {
                virus[x]=true;
                q.push({x,0});
            }
            int ans=0;
            while(!q.empty())
            {
                auto front = q.front();
                q.pop();
                int curr_Node = front.first;
                int curr_Time = front.second;
                cout<<"{ "<<curr_Node<<", "<<curr_Time<<" }"<<endl;
                ans = max(ans,curr_Time);
                for(auto x: adj[curr_Node])
                {
                    if(virus[x]==false)
                    {
                        virus[x]=true;
                        q.push({x,curr_Time+1});
                    }
                }

            }
            for(int i=1;i<=Vertices;i++)
            {
                if(virus[i]==false)
                    return -1;
            }
            return ans;
        } 

};
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
    graph g(v);
    for(int i=0;i<e;i++)
    {
        int a, b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    vector<int> vec{10,5};
    cout<<g.minTimeForSpreadingVirus(vec);
    return 0;
}