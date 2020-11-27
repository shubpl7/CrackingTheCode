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
              string s,a;
              s.PB('#');
              cin>>a;
              s+=a;
              vector<bool> marked(n+1,false);
              vector<int> evnAtOdd,OddAtEven, odd, even;
              for(int i=1;i<=n;i++)
              {
                     if(i&1)
                     {
                            if((s[i]-'0')%2==0)
                            {
                                   evnAtOdd.PB(i);
                            }
                            else
                                   odd.PB(i);
                     }
                     else
                     {
                            if((s[i]-'0')%2!=0)
                            {
                                   OddAtEven.PB(i);
                            }
                            else
                                   even.PB(i);
                     } 
              }
              int rem=n,raze=1,breach=0;
              while(rem>1)
              {
                     if(raze)
                     {
                            if(evnAtOdd.size()>0)
                            {
                                   int k=*evnAtOdd.begin();
                                   marked[k]=true;
                                   evnAtOdd.erase(evnAtOdd.begin());
                                   rem--;
                                   raze=0;breach=1;
                            }
                            else
                            {
                                   int k=*odd.begin();
                                   marked[k]=true;
                                   odd.erase(odd.begin());
                                   rem--;
                                   raze=0;breach=1;
                            }
                            
                     }
                     else
                     {
                            if(OddAtEven.size()>0)
                            {
                                   int k=*OddAtEven.begin();
                                   marked[k]=true;
                                   OddAtEven.erase(OddAtEven.begin());
                                   rem--;
                                   raze=1;breach=0;
                            }
                            else
                            {
                                   int k=*even.begin();
                                   marked[k]=true;
                                   even.erase(even.begin());
                                   rem--;
                                   raze=1;breach=0;
                            }
                     }
                     
              }
              for(int i=1;i<=n;i++)
              {
                     if(marked[i]==false)
                     {
                            if((s[i]-'0')%2==0)
                            {
                                   cout<<"2\n";
                            }
                            else
                            {
                                   cout<<"1\n";
                            }
                            break;
                            
                     }
              }
       }
       return 0;
}