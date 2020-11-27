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
vector<string> names;
int n;
unordered_map<char,vector<char>> adj;
unordered_map<char,bool> vis;
unordered_map<char,int> currentpath;
bool IsCycle(int src)
{
       vis[src]=true;
       currentpath[src]=1;
       for(auto x:adj[src])
       {
              if(!vis[x])
              {
                     bool sub = IsCycle(x);
                     if(sub)
                            return true;
              }
              else if(vis[x]==true and currentpath[x]==1)
              {
                     return true;
              }
       }       
       currentpath[src]=0;
       return false;
}
void topsort()
{
       unordered_map<char,int> indegree;
       for(char ch='a';ch<='z';ch++)
              indegree[ch]=0;
       for(auto x:adj)
       {
              for(auto y:x.se)
                     indegree[y]++;
       }
       queue<int> q;
       for(auto x:indegree)
       {
              if(x.se==0)
                     q.push(x.fi);
       }
       while(!q.empty())
       {
              char u= q.front();
              q.pop();
              cout<<u;
              for(auto x:adj[u])
              {
                     indegree[x]--;
                     if(indegree[x]==0)
                            q.push(x);
              }
       }
}
void constructGraph()
{
       for(int i=0;i<n-1;i++)
       {
              string up=names[i];
              string down=names[i+1];
              int upi=0,downi=0;
              int k=min(up.size(),down.size());
              int j;
              for(j=0;j<k;j++)
              {
                     if(up[j]!=down[j])
                     {
                            adj[up[j]].PB(down[j]);
                            break;
                     }
              }
              if(j==k)
              {
                     if(up.size()>down.size())
                     {
                            cout<<"Impossible";
                            exit(0);
                            return;
                     }
              }
       }
       for(char ch='a';ch<='z';ch++)
       {
              vis[ch]=false;
       }
       // for(auto x:adj)
       // {
       //        cout<<x.fi<<"-->";
       //        for(auto y:x.se)
       //               cout<<y<<" ";
       //        cout<<endl;
       // }
       bool cyc=false;
       for(char ch='a';ch<='z';ch++)
       {
              if(!vis[ch])
              {
                     if(IsCycle(ch))
                     {
                            cout<<"Impossible";
                            exit(0);
                            //return 0;
                            return;
                     }
              }
       }
       topsort();
}
// void LinkedList::Print()
// {
//        Student *temp=head;
//        while(temp)
//        {
//               cout<<temp->name<<" "<<temp->id<<"--->";
//               temp=temp->link;
//        }
//        cout<<endl;
// }
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       cin>>n;
       for(int i=0;i<n;i++)
       {
              string name;
              cin>>name;
              names.PB(name);
       }
       constructGraph();
       return 0;
}