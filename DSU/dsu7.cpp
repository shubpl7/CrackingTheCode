#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define fi first
#define se second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
int n;
VPII build,close;
VI parents, ranks;
int find(int a)
{
       if(parents[a]==-1)
              return a;
       return parents[a]=find(parents[a]);
}
void unite(int s1,int s2)
{
       // int s1=find(a);
       // int s2=find(b);
       if(s1!=s2);
              parents[s1]=s2;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       cin>>n;
       parents.resize(n+1,-1);
       ranks.resize(n+1,1);
       for(int i=1;i<=n-1;i++)
       {
              int a,b;
              cin>>a>>b;
              int s1=find(a);
              int s2=find(b);
              if(s1==s2)
                     close.PB({a,b});
              else
              {
                     unite(s1,s2);
              }
              
       }
       VI interm;
       for(int i=1;i<=n;i++)
              if(parents[i]==-1)
                     interm.PB(i);

       int sz=interm.size();
       for(int i=0;i<sz-1;i++)
       {
              build.PB({interm[i],interm[i+1]});
       }
       cout<<build.size()<<endl;
       for(int i=0;i<build.size();i++)
       {
              cout<<close[i].fi<<" "<<close[i].se<<" "<<build[i].fi<<" "<<build[i].se<<endl;
       }
       return 0;
}