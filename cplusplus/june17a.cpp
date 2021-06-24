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
       int phy, chem, maths;
       float avg = 0;
};

void cal_avg(student * p)
{
       float res = (float)(p->maths+p->phy+p->chem)/3;
       p->avg = res;
       p->name = " arnav";
       cout<<"I am in cal. avg avg. is "<<p->avg<<endl;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       
       student s1;
       s1.name="ravi";
       s1.id=2;s1.maths=10;s1.phy=15;s1.chem=20;
       cout<<"name is :"<<s1.name<<endl;
       student * ptr = &s1;
       cal_avg(ptr);
       cout<<"name is :"<<s1.name<<endl;
       cout<<"I ma in main avg .is "<<s1.avg;
       return 0;
}