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
VI tree;
VI A;
void build(int idx,int s,int e)
{
       if(s==e)
       {
              tree[idx]=A[s];
              return;
       }
       int m=(s+e)/2;
       build(2*idx,s,m);
       build(2*idx+1,m+1,e);
       int level = log2(e-s+1);
       if(level%2==0)
       {
              tree[idx]=tree[2*idx]^tree[2*idx+1];
       }
       else
       {
              tree[idx]=tree[2*idx]|tree[2*idx+1];
       }
       
}
void update(int pos,int val,int idx,int s,int e)
{
       if(s==e)
       {
              tree[idx]=val;
              return;
       }
       int m=(s+e)/2;
       if(pos<=m)
       {
              update(pos,val,2*idx,s,m);
       }
       else
       {
              update(pos,val,2*idx+1,m+1,e);
       }
       int level = log2(e-s+1);
       if(level%2==0)
       {
              tree[idx]=tree[2*idx]^tree[2*idx+1];
       }
       else
       {
              tree[idx]=tree[2*idx]|tree[2*idx+1];
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
       int n,m;
       cin>>n>>m;
       int s=1LL<<n;
       A.resize(s);
       tree.resize(4*s+1);
       for(int i=0;i<s;i++)
       {
              cin>>A[i];
       }
       build(1,0,s-1);
       while(m--)
       {
              int p,b;
              cin>>p>>b;
              update(p-1,b,1,0,s-1);
              cout<<tree[1]<<endl;
       }
       return 0;
}