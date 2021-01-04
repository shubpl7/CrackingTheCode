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
VI lazy;
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
       //look-up for any pending updates
       if(lazy[idx]!=0)
       {
              tree[idx]+=(e-s+1)*lazy[idx];
              if(s!=e)
              {
                     lazy[2*idx]+=lazy[idx];
                     lazy[2*idx+1]+=lazy[idx];
              }
              lazy[idx]=0;
       }
       if(qs==s && qe==e)
       {
              return tree[idx];
       }
       int m=(s+e)/2;
       int left = sumUtility(s,m,qs,min(qe,m),2*idx,tree);
       int right = sumUtility(m+1,e,max(m+1,qs),qe,2*idx+1,tree);
       return left+right;

}
int sum(int qs,int qe,int *tree,int n)
{
       int idx=1;
       int ans = sumUtility(0,n-1,qs,qe,idx,tree);
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
void update2(int qs,int qe,int s,int e,int idx,int *tree,int val)
{
       if(qs>qe)
              return;
       //look-up for any pending updates
       if(lazy[idx]!=0)
       {
              tree[idx]+=(e-s+1)*lazy[idx];
              if(s!=e)
              {
                     lazy[2*idx]+=lazy[idx];
                     lazy[2*idx+1]+=lazy[idx];
              }
              lazy[idx]=0;
       }
       if(s==qs && e==qe)
       {
              tree[idx]+=(e-s+1)*val;
              if(s!=e)
              {
                     lazy[2*idx]+=val;
                     lazy[2*idx+1]+=val;
              }
              return;
       }
       int m=(s+e)/2;
       //left
       update2(qs,min(qe,m),s,m,2*idx,tree,val);
       //right
       update2(max(m+1,qs),qe,m+1,e,2*idx+1,tree,val);
       
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
       int arr[]={5,-7,2,4,11,6,-3,8};
       int n=sizeof(arr)/sizeof(arr[0]);
       int tree[4*n+1]={0};
       lazy.resize(4*n+1,0);
       build(0,n-1,1,tree,arr);
       for(int i=1;i<4*n+1;i++)
              cout<<tree[i]<<" ";
       cout<<endl;
       update2(2,4,0,n-1,1,tree,10);
       for(auto x:lazy)
              cout<<x<<" ";
       cout<<endl;
       for(int i=1;i<4*n+1;i++)
              cout<<tree[i]<<" ";
       cout<<endl;
       cout<<"Update 2 \n";
       update2(0,3,0,n-1,1,tree,5);
       for(auto x:lazy)
              cout<<x<<" ";
       cout<<endl;
       for(int i=1;i<4*n+1;i++)
              cout<<tree[i]<<" ";
       cout<<endl;

       cout<<sum(2,4,tree,n)<<endl;
       for(auto x:lazy)
              cout<<x<<" ";
       cout<<endl;
       for(int i=1;i<4*n+1;i++)
              cout<<tree[i]<<" ";
       cout<<endl;
       cout<<sum(1,3,tree,n);
       return 0;
}