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
int MIN = -200000;
struct Node{
       int PS;
       int SS;
       int TS;
       int MS;
};
int n;
vector<Node> tree;
VI arr;
void build(int idx,int s,int e)
{
       if(s==e)
       {
              tree[idx] = (Node){arr[s],arr[s],arr[s],arr[s]};
              return;
       }
       int m=(s+e)/2;
       build(2*idx,s,m);
       build(2*idx+1,m+1,e);
       Node left = tree[2*idx];
       Node right = tree[2*idx+1];
       tree[idx].PS = max(left.TS+right.PS,left.PS);
       tree[idx].SS = max(right.TS+left.SS,right.SS);
       tree[idx].TS = left.TS+right.TS;
       tree[idx].MS = max(left.SS+right.PS,max(left.MS,right.MS));
}
Node MaxSumQuery(int idx,int s,int e,int qs, int qe)
{
       if(qs>qe)
       {
              return (Node){MIN,MIN,MIN,MIN};
       }
       if(qs==s && qe==e)
       {
              return tree[idx];
       }
       int m=(s+e)/2;
       Node left = MaxSumQuery(2*idx,s,m,qs,min(qe,m));
       Node right = MaxSumQuery(2*idx+1,m+1,e,max(m+1,qs),qe);
       Node temp;
       temp.PS = max(left.TS+right.PS,left.PS);
       temp.SS = max(right.TS+left.SS,right.SS);
       temp.TS = left.TS+right.TS;
       temp.MS = max(left.SS+right.PS,max(left.MS,right.MS));
       return temp;

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
       arr.resize(n+1);
       tree.resize(4*n+1);
       for(int i=1;i<=n;i++)
              cin>>arr[i];
       build(1,1,n);
       int m;
       cin>>m;
       while(m--)
       {
              int x,y;
              cin>>x>>y;
              cout<<MaxSumQuery(1,1,n,x,y).MS<<endl;
       }
       return 0;
}