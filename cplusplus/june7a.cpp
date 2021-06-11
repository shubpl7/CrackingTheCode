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
struct student{
       string name;
       int id;
};
int32_t main()
{
       // ios_base::sync_with_stdio(false);
       // cin.tie(NULL);
       // #ifndef ONLINE_JUDGE
       // freopen("../input.txt","r",stdin);
       // freopen("../output.txt","w",stdout);
       // #endif
       int n;
       cout<<"Enter class size";
       cin>>n;
       
       student * p = new student[n];

       for(int i=0;i<n;i++)
       {
              cout<<"Enter the name of the "<<i<<" th student: \n";
              cin>>p[i].name;
              cout<<"Enter the id of the "<<i<<" th student: \n";
              cin>>p[i].id;
       }
       int k;
       cout<<"Find the id of which student?\n";
       cin>>k;
       cout<<"Id of "<<k<<" the student is: "<<p[k].id;
       delete []p;       
       return 0;
}