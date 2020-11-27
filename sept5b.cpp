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
              int n;
              cin>>n;
              int temp=n;
              vector<pair<int,int>> v;
              for(int i=2;i<=sqrt(n);i++)
              {
                     if(n%i==0)
                     {
                            int cnt=0;
                            while(n%i==0)
                            {
                                   cnt++;
                                   n=n/i;
                            }
                            v.push_back({i,cnt});

                     }
              }
              if(n!=1)// only when n is prime
                     v.push_back({n,1});
              n=temp;
              // for(auto x:v)
              // {
              //        cout<<x.fi<<" "<<x.se<<endl;
              // }
              if(v.size()>=3)
              {
                     cout<<"YES\n";
                     int a=v[0].fi;
                     int b=v[1].fi;
                     int c=n/(a*b);
                     cout<<a<<" "<<b<<" "<<c<<endl;
              }
              else if (v.size()==2)
              {
                     if(v[0].se+v[1].se>=4)
                     {
                            cout<<"YES\n";
                            int a=v[0].fi;
                            int b=v[1].fi;
                            int c=n/(a*b);
                            cout<<a<<" "<<b<<" "<<c<<endl;
                     }
                     else
                     {
                            cout<<"NO\n";
                     }
                     
              }
              else if(v.size()==1)
              {
                     if(v[0].se>=6)
                     {
                            cout<<"YES\n";
                            int a=(int)pow(v[0].fi,1);//2^1
                            int b=(int)pow(v[0].fi,2);//2^2
                            int c=n/(a*b);
                            cout<<a<<" "<<b<<" "<<c<<endl;
                     }
                     else
                            cout<<"NO\n";
              }
       }
       return 0;
}