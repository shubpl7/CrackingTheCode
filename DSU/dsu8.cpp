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
int N = 100005;
class dsu{
       public:
       VI parents;
       dsu()
       {
              parents.resize(N,-1);
       }
       int find(int a)
       {
              if(parents[a]==-1)
                     return a;
              return parents[a]=find(parents[a]);
       }
       void unite(int a,int b)
       {
              int s1=find(a);
              int s2=find(b);
              if(s1!=s2)
              {
                     parents[s1]=s2;
              }
       }

       
};
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
       vector<dsu *> shubh(m+1);
       for(int i=1;i<=m;i++)
       {
              shubh[i]=new dsu();
       }
       for(int i=1;i<=m;i++)
       {
              int a,b,c;
              cin>>a>>b>>c;
              shubh[c]->unite(a,b);
       }
       int q;
       cin>>q;
       while(q--)
       {
              int a,b;
              cin>>a>>b;
              int cnt=0;
              for(int i=1;i<=m;i++)
              {
                     if((shubh[i]->find(a))==(shubh[i]->find(b)))
                            cnt++;
              }
              cout<<cnt<<endl;
       }
       return 0;
}