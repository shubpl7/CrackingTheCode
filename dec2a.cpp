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
VVI adj;
int path;
string s;
VI A;
void DFS(int u, char src,int count,int par)
{
       //cout<<"DFS"<<" "<<u<<" "<<count<<" "<<src<<" "<<par<<endl;
       path=max(path,count);
       for(auto x:adj[u])
       {
              if(x==par)
                     continue;
              if(s[x]!=src)
              {
                     DFS(x,s[x],count+1,u);
              }
              
       }
}
void FindLongestPath()
{
       int n=A.size();
       adj.resize(n);
       for(int i=1;i<n;i++)
       {
              int par=A[i];
              adj[par].PB(i);
              adj[i].PB(par);
       }
       path=0;
       for(int i=0;i<n;i++)
       {
              int curr=1;
              DFS(i,s[i],curr,-1);
       }
       cout<<path<<endl;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       cin>>s;
       A.resize(s.length());
       for(auto &x:A)
              cin>>x;
       FindLongestPath();

       return 0;
}