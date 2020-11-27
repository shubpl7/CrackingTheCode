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
const int N = 100005;
int n;
bool isPrime(int n)
{
       //time complexity is O(sqrt(n))
       if(n==1)
              return false;
       if(n==2)
              return true;
       for(int i=2;i*i<=n;i++)
       {
              if(n%i==0)
                     return false;
       }
       return true;
}

void seive()
{
       //vector<bool> P(N,true);
       bitset<N> b;
       b.set();
       b[1]=0;
       for(int i=2;i<=n;i++)
       {
              if(b[i]==1)//i is prime
              {
                     cout<<i<<" ";
                     for(int j=i*i;j<=n;j+=i)
                     {
                            if(b[j])
                                   b[j]=0;
                     }
              }
       }







       // for(int i=4;i<=n;i+=2)
       //        P[i]=false;

       // P[1]=false;
       // for(int i=2;i<=n;i++)
       // {
       //        if(P[i]==true)
       //        {
       //               //cout<<i<<" ";
       //               for(int j=i*i;j<=n;j=j+i)
       //               {
       //                      if(P[j]==true)
       //                             P[j]=false;
       //               }
       //        }
       // }
       // for(int i=2;i<=n;i++)
       // {
       //        if(P[i]==true)
       //               cout<<i<<endl;
       // }
}


int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       cin>>n;
       seive();
       return 0;
}