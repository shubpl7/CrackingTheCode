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


int calc_area(int l,int b)
{
       int area = l*b;
       return area;
}
int calc_peri(int l,int b)
{
       int perimeter = 2*(l+b);
       return perimeter;

}

void calc_P_A(int *a,int *b, int *c, int *d)
{
       cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
       cout<<*a<<" "<<*b<<" "<<*c<<" "<<*d<<endl;
       *c = 2*((*a)+(*b));
       *d = (*a)*(*b);
}

int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       
       int l=10,b=5;
       int perimeter=0,area=0;

       calc_P_A(&l,&b,&perimeter,&area);
       cout<<perimeter<<" "<<area<<endl;
       return 0;
}