//https://www.spoj.com/problems/NITTROAD/
/*Author : Shubham Pal
B-Tech MANIT CSE
*/
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
struct edge{
       int a,b;
       bool marked;
};
VI parents;
VI ranks;
vector<edge> edges;
int n;
int find(int x)
{
       if(parents[x]==-1)
              return x;
       return parents[x]=find(parents[x]);
}
void unite(int a,int b)
{
       if(a!=b)
       {
              if(ranks[a]>ranks[b])
              {
                     parents[b]=a;
                     ranks[a]+=ranks[b];
              }
              else
              {
                     parents[a]=b;
                     ranks[b]+=ranks[a];
              }
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
       int t;
       cin>>t;
       while(t--)
       {
              cin>>n;
              edges.resize(n+1);
              parents.resize(n+1,-1);
              ranks.resize(n+1,1);
              for(int i=1;i<=n-1;i++)
              {
                     int x,y;
                     cin>>x>>y;
                     edges[i].a=x;edges[i].b=y;
                     edges[i].marked=true;
              }
              int Q;
              cin>>Q;
              stack<int> query;
              while(Q--)
              {
                     char ch;
                     cin>>ch;
                     if(ch=='Q')
                     {
                            query.push(0);
                     }
                     else if(ch=='R')
                     {
                            int alpha;
                            cin>>alpha;
                            query.push(alpha);
                            edges[alpha].marked=false;
                     }
                     
              }
              stack<int> ans;
              //store the connected compoenents which is not marked yet.
              int connPair = 0;
              for(int i=1;i<=n-1;i++)
              {
                     if(edges[i].marked)
                     {
                            int s1=find(edges[i].a);
                            int s2=find(edges[i].b);
                            if(s1!=s2)
                            {
                                   connPair+=(ranks[s1]*ranks[s2]);
                                   unite(s1,s2);
                            }
                     }
              }
              int disConnPair=(n*(n-1))/2 - connPair;
              while(!query.empty())
              {
                     int top=query.top();
                     query.pop();
                     if(top==0)
                            ans.push(disConnPair);
                     else
                     {
                            int s1=find(edges[top].a);
                            int s2=find(edges[top].b);
                            if(s1!=s2)
                            {
                                   disConnPair-=(ranks[s1]*ranks[s2]);
                                   unite(s1,s2);
                            }
                     }
                     

              }
              while(!ans.empty())
              {
                     cout<<ans.top()<<endl;
                     ans.pop();
              }
              cout<<endl;
              edges.clear();
              parents.clear();
              ranks.clear();

       }
       return 0;
}