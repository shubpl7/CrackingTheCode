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
VI S,A;
bool flag=false;
void DFS(int src,int par,int level)
{
       if(flag)
              return;
       if(level%2==0)
       {
              //A[src]=0;
              int choice=INT64_MAX;
              for(auto x:adj[src])
              {
                     if(x==par)
                            continue;
                     choice=min(choice,S[x]);
              }
              if(choice==INT64_MAX)
              {
                     A[src]=0;
                     S[src]=A[src]+S[par];
              }
              else
              {
                     A[src]=choice-S[par];
                     if(A[src]<0)
                     {
                            flag=true;
                            return;
                     }       
                     S[src]=A[src]+S[par];
              }
       }
       else
       {
              if(par==-1)
              {
                     A[src]=S[src];
              }
              else
              {
                     if(S[src]-S[par]<0)
                     {
                            flag=true;
                            return;
                     }       
                     A[src]=S[src]-S[par];
              }
       }
       //cout<<"DFS "<<src<<" "<<par<<" "<<A[src]<<" "<<S[src]<<" "<<S[par]<<endl;
       for(auto x:adj[src])
       {
              if(x==par)
                     continue;
              DFS(x,src,level+1);
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
       int n;
       cin>>n;
       adj.resize(n+1);
       A.resize(n+1);
       S.resize(n+1);
       for(int i=2;i<=n;i++)
       {
              int p;
              cin>>p;
              adj[p].PB(i);
              adj[i].PB(p);
       }
       for(int i=1;i<=n;i++)
       {
              int a;
              cin>>a;
              S[i]=a;
       }
       DFS(1,-1,1);
       if(flag)
              cout<<"-1";
       else
       {
              int sum=0;
              for(int i=1;i<=n;i++)
              {

                     //cout<<A[i]<<" ";
                     sum+=A[i];
              }
             //cout<<endl;
              cout<<sum;
       }
       return 0;
}