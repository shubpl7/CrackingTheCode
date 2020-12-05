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
VI parent;
VI ranks;
int n,m;
int find(int a)
{
       if(parent[a]==-1)
              return a;
       parent[a]=find(parent[a]);
       return parent[a];
}
void union_set(int a,int b)
{
       int s1=find(a);
       int s2=find(b);
       if(s1!=s2)
       {
              if(ranks[s1]>ranks[s2])
              {
                     parent[s2]=s1;
                     ranks[s1]+=ranks[s2];
              }
              else
              {
                     parent[s1]=s2;
                     ranks[s2]+=ranks[s1];
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
       cin>>n>>m;
       ranks.resize(n,1);
       parent.resize(n,-1);
       for(int i=0;i<m;i++)
       {
              int k;
              cin>>k;
              VI friends(k);
              for(int i=0;i<k;i++)
              {
                     int a;
                     cin>>a;
                     a--;
                     friends[i]=a;
              }
              for(int i=0;i<k-1;i++)
              {
                     int a=friends[i];
                     int b=friends[i+1];
                     union_set(a,b);
              }
       }
       for(int i=0;i<n;i++)
       {
              cout<<ranks[find(i)]<<" ";
       }
       return 0;
}