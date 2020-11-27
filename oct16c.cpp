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
VVI adj;
VI A,S;
bool flag=false;
void DFS(int curr,int par, int level)
{
       if(flag)
              return;
       if(level%2==0)
       {
              int choice = INT64_MAX;
              for(auto x:adj[curr])
              {
                     if(x==par)
                            continue;
                     choice=min(choice,S[x]);
              }
              if(choice==INT64_MAX)
              {
                     A[curr]=0;
                     S[curr]=A[curr]+S[par];
              }
              else
              {
                     S[curr]=choice;
                     A[curr]=S[curr]-S[par];
                     if(A[curr]<0)
                     {
                            flag=true;
                            return;
                     }
              }
              
       }
       else
       {
              if(par==-1)
              {
                     A[curr]=S[curr];
              }
              else
              {
                     A[curr]=S[curr]-S[par];
                     if(A[curr]<0)
                     {
                            flag=true;
                            return;
                     }
              }

       }
       //cout<<"DFS "<<curr<<" "<<par<<" "<<level<<" "<<A[curr]<<endl;
       for(auto x:adj[curr])
       {
              if(x==par)
                     continue;
              DFS(x,curr,level+1);
       }
       
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       cin>>n;
       adj.resize(n+1);
       A.resize(n+1);
       S.resize(n+1);
       for(int i=2;i<=n;i++)
       {
              int p;
              cin>>p;
              adj[i].PB(p);
              adj[p].PB(i);
       }
       for(int i=1;i<=n;i++)
       {
              cin>>S[i];
       }
       DFS(1,-1,1);
       if(flag)
              cout<<"-1";
       else
       {
              int sum=0;
              for(int i=1;i<=n;i++)
                     sum+=A[i];
              cout<<sum;
       }
       return 0;
}