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
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       
       unordered_map<string,vector<string>> mp;

       int n;
       cin>>n;

       for(int i=1;i<=n;i++)
       {
              string cusName;
              cin>>cusName;
              int ordersize;
              cin>>ordersize;
              for(int j=1;j<=ordersize;j++)
              {
                     string dishname;
                     cin>>dishname;
                     mp[cusName].push_back(dishname);
              }
       }


       map<string,int> menu;

       menu["rice"]=100;
       menu["poha"]=50;
       menu["dal"]=80;
       menu["salad"]=50;
       menu["paneer"]=150;
       menu["chicken"]=200;
       menu["coffee"]=10;
       menu["biryani"]=100;
       menu["milk"]=15;
       menu["juice"]=25;

       for(auto x:mp)
       {
              cout<<x.first<<": ";
              for(auto y:x.second)
              {
                     cout<<y<<"-->";
              }
              cout<<endl;
       }


       //finding bill for each customer
       
       for(auto x:mp)
       {
              cout<<"Bill for customer "<<x.first<<" is : ";
              int bill=0;
              for(auto y: x.second)
              {
                     bill=bill+menu[y];
              }
              cout<<bill;
              cout<<endl;
       }
       return 0;
}