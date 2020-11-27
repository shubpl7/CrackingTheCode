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
class Graph{
       public:
              int n=26;
              string pass;
              bool IsCycle=false;
              Graph(string s)
              {
                     this->pass=s;
              }
              unordered_map<char,set<char>> adj;
              unordered_map<char,bool> vis;
              unordered_map<char,int> depth;
              vector<char> nodes;
              void DFS(char src,char par,int level)
              {
                     //cout<<"DFS "<<src<<" "<<par<<" "<<level<<endl;
                     nodes.PB(src);
                     vis[src]=true;
                     depth[src]=level;
                     //cout<<depth[src]<<endl;
                     for(auto x:adj[src])
                     {
                            if(x==par)
                                   continue;
                            if(depth[x]!=-1)
                            {
                                   //cout<<"Cycle between "<<x<<" ans "<<src<<endl;
                                   IsCycle=true;
                            }
                            if(!vis[x])
                                   DFS(x,src,level+1);
                     }
              }
              void FindKeyBoardPattern()
              {

                     for(int i=0;i<pass.size()-1;i++)
                     {
                            char a=pass[i];
                            char b=pass[i+1];
                            adj[a].insert(b);
                            adj[b].insert(a);
                     }
                     for(auto x:adj)
                     {
                            depth[x.fi]=-1;
                     }
                     char src;
                     bool flag=false;
                     for(auto x:adj)
                     {
                            if(x.se.size()==1)
                            {
                                   src=x.fi;
                                   flag=true;
                                   break;
                            }
                     }
                     if(!flag)
                            src=pass[0];
                     DFS(src,'A',0);
                     if(IsCycle)
                     {
                            cout<<"NO\n";
                            return;
                     }
                     cout<<"YES\n";
                     for(auto x:nodes)
                            cout<<x;
                     for(char ch='a';ch<='z';ch++)
                     {
                            if(vis.find(ch)==vis.end())
                            {
                                   cout<<ch;
                            }
                     }
                     cout<<endl;
              }
};
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int t;
       cin>>t;
       while(t--)
       {
              string s;
              cin>>s;
              Graph G(s);
              G.FindKeyBoardPattern();
       }
       return 0;
}