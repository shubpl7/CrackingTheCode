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
              VPII pal;
              for(int i=2;i*i<=n;i++)
              {
                     //cout<<"i:"<<i<<endl;
                     if(n%i==0)
                     {
                            int cnt=0;
                            while(n%i==0)
                            {
                                   // cout<<i<<" ";
                                   n/=i;
                                   cnt++;
                            }
                            pal.PB({i,cnt});
                     }
              }
              if(n!=1)// n is prime
                     pal.PB({n,1});
              n=temp;
              if(pal.size()>=3)
              {
                     cout<<"YES\n";
                     int a=(int)pow(pal[0].fi,pal[0].se);
                     int b=(int)pow(pal[1].fi,pal[1].se);
                     int c=n/(a*b);
                     cout<<a<<" "<<b<<" "<<c<<endl;
              }
              else if(pal.size()==2)
              {
                     // if(pal[0].se>=2 && pal[1].se>=2)
                     // {
                     //        cout<<"YES\n";
                     //        int a= pal[0].fi;
                     //        int b=pal[1].se;
                     //        int c =n/(a*b);
                     //        cout<<a<<" "<<b<<" "<<c<<endl;
                     // }
                     int a =pal[0].fi;
                     pal[0].se--;
                     int b=pal[1].fi;
                     pal[1].se--;
                     if(pal[0].se+pal[1].se>=2)
                     {
                            int c=n/(a*b);
                            cout<<"YES\n";
                            cout<<a<<" "<<b<<" "<<c<<endl;
                     }
                     else
                            cout<<"NO\n";
              }
              else if(pal.size()==1)
              {
                     if(pal[0].se>=6)
                     {
                            cout<<"YES\n";
                            int a=(int)pow(pal[0].fi,1);
                            int b=(int)pow(pal[0].fi,2);
                            //int c=(int)pow(pal[0].fi,pal[0].se-3);
                            int c=n/(a*b);
                            //cout<<a<<" "<<b<<" "<<n<<" "<<a*b<<" "<<(n/(a*b));
                            cout<<a<<" "<<b<<" "<<c<<endl;
                     }
                     else
                     {
                            cout<<"NO\n";
                     }
                     
              }
              // for(auto x:pal)
              // {
              //        cout<<x.first<<" "<<x.se<<endl;
              // }
       }
       
       return 0;
}