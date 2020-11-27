#include<bits/stdc++.h>
//*************** Constraints are always Imaginary,I'm real **************
using namespace std;
#define int long long 
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
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
const int N=100005;
vector<bool> P;
bitset<N> b;
VI primes;
bool prime(int n)
{
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
       P.resize(N+1,true);//all primes
       for(int i=2;i<=N;i+=2)
              P[i]=false;
       P[2]=true;
       P[1]=false;P[0]=false;
       for(int j=2;j<=N;j++)
       {
              if(P[j]==true)
              {
                     primes.PB(j);
                     for(int i=j*j;i<=N;i+=j)
                     {
                            if(P[i])
                                   P[i]=false;
                     }
              }
       }
}

void BitSeive()
{
       b.set();
       b[0]=0;b[1]=0;
       for(int i=4;i<=N;i+=2)
              b[i]=0;
       b[2]=1;
       for(int i=2;i<=N;i++)
       {
              if(b[i])
              {
                     primes.PB(i);
                     for(int j=i*i;j<=N;j+=i)
                     {
                            b[j]=0;
                            
                     }
              }
       }
}
void PrintPrimes(int a,int b)
{
       // for(int i=a;i<=b;i++)
       // {
       //        if(prime(i))
       //               cout<<i<<" ";
       // }
       seive();
       for(int i=a;i<=b;i++)
       {
              if(P[i]==true)
                     cout<<i<<" ";
       }
}
bool LargePrime(int n)
{
       if(n<N)
       {
              return b[n]==1?true:false;
       }
       for(int i=0;primes[i]*primes[i]<=n;i++)
       {
              if(n%primes[i]==0)
                     return false;
       }
       return true;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       // int a=1,b=100;
       // PrintPrimes(a,b);
       BitSeive();
       //2147483647
       if(LargePrime(2147483647))
              cout<<"yes It is Prime\n";
       else
              cout<<"No Prime\n";
       return 0;
}