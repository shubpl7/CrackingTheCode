using namespace std;
#include<bits/stdc++.h>
#define pb push_back 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int N = 1e5+3;

set<int>color_neighb[N];
vector<int>gr[N];
int color[N];
int n,m;

signed main()
{
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
    IOS;
    cin>>n>>m;

    for ( int i = 1; i<=n; ++i )
    {
    	cin>>color[i];
    }

    for ( int i = 1; i<=m; ++i )
    {
    	int u,v;
    	cin>>u>>v;
    	gr[u].push_back(v);
    	gr[v].push_back(u);
    }

    for ( int i = 1; i<=n; ++i )
    {
    	for ( int it : gr[i] )
    		if ( color[it]!=color[i] )
    			color_neighb[ color[i] ].insert( color[it] );
    }

    int ans = -1;
    int max_v = -1;

    for ( int i = 1; i<N; ++i )
    {
    	if ( (int)color_neighb[i].size()>max_v )
    	{
    		max_v = color_neighb[i].size();
    		ans = i;
    	}
    }

    if ( max_v == 0 )
    {
    	ans = N;
    	for ( int i = 1; i<=n; ++i )
    		ans = min(ans,color[i]);
    }

    cout<<ans<<"\n";
}
