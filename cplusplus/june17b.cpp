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

int add(int x,int y,int z=0,int s=0)
{
       cout<<endl;
       return x+y+z+s;
}

// return by pointer

int * fun()
{
       int * p  = new int[5];
       for(int i=0;i<5;i++)
              *(p+i)=i*i;
       return p;
}

//return by refernce

int & fun1(int &x)
{
       int &y = x;
       y+=10;
       return y;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       // int * ptr = fun();
       // for(int i=0;i<5;i++)
       //        cout<<ptr[i]<<" ";

       int a=5;
       fun1(a)=19;
       cout<<"\n"<<a<<endl;
       return 0;
}