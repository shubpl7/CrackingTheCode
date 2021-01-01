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
void build(int s,int e,int idx,int *tree,int *arr)
{
       if(s==e)
       {
              tree[idx]=arr[s];
              return;
       }
       int m=(s+e)/2;
       build(s,m,2*idx,tree,arr);
       build(m+1,e,2*idx+1,tree,arr);
       tree[idx]=tree[2*idx]+tree[2*idx+1];
}
int sumUtility(int s,int e,int qs,int qe,int idx,int *tree)
{
       if(qs>qe)
              return 0;
       if(qs==s && qe==e)
       {
              return tree[idx];
       }
       int m=(s+e)/2;
       int left = sumUtility(s,m,qs,min(qe,m),2*idx,tree);
       int right = sumUtility(m+1,e,max(m+1,qs),qe,2*idx+1,tree);
       return left+right;

}
int sum(int qs,int qe,int *tree)
{
       int idx=1;
       int ans = sumUtility(0,4,qs,qe,idx,tree);
       return ans;
}
void update(int pos,int s,int e,int idx,int *tree)
{
       if(s==e)
       {
              tree[idx]+=2;
              return;
       }
       int m=(s+e)/2;
       if(pos<=m)
       {
              update(pos,s,m,2*idx,tree);
       }
       else
       {
              update(pos,m+1,e,2*idx+1,tree);
       }
       tree[idx]=tree[2*idx]+tree[2*idx+1];
       
}
void update2(int qs,int qe,int s,int e,int idx,int *tree)
{
       if(qs>qe)
              return;
       if(s==e)
       {
              tree[idx]+=2;
              return;
       }
       int m=(s+e)/2;
       //left
       update2(qs,min(qe,m),s,m,2*idx,tree);
       //right
       update2(max(m+1,qs),qe,m+1,e,2*idx+1,tree);
       
       tree[idx]=tree[2*idx]+tree[2*idx+1];
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       int arr[]={1,3,-2,8,-7};
       int n=5;
       int tree[4*n+1]={0};
       build(0,n-1,1,tree,arr);
       for(int i=1;i<4*n+1;i++)
              cout<<tree[i]<<" ";
       cout<<endl;
       cout<<sum(2,4,tree);
       cout<<endl;
       // update(1,0,n-1,1,tree);
       // for(int i=1;i<4*n+1;i++)
       //        cout<<tree[i]<<" ";
       update2(1,3,0,n-1,1,tree);
       for(int i=1;i<4*n+1;i++)
              cout<<tree[i]<<" ";
       cout<<endl;
       cout<<sum(2,3,tree);
       return 0;
}