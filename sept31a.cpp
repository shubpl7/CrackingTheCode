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
int FindInSortedRotated(VI &a,int key)
{
       int l=0,r=a.size()-1;
       while (l<=r)
       {
              int mid=l+(r-l)/2;
              cout<<l<<" "<<r<<" "<<mid<<endl;
              if(a[mid]==key)
                     return mid;
              if(a[mid]>=a[l])
              {
                     if(key>=a[l] && key<a[mid])
                            r=mid-1;
                     else
                            l=mid+1;
              }
              else
              {
                     if(key<=a[r] && key>a[mid])
                            l=mid+1;
                     else
                            r=mid-1;
              }
       }
       return -1;
       
}
int FindPivot(VI &a)
{
       int l=0,r=a.size()-1;
       while(l<=r)
       {
              int mid=l+(r-l)/2;
              cout<<l<<" "<<r<<" "<<mid<<endl;
              if(mid==a.size()-1 || (a[mid+1]<a[mid]))
                     return a[mid];
              if(a[mid]>=a[l])
              {
                     l=mid+1;
              }
              else
              {
                     r=mid-1;
              }
              
       }
       return -1;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       VI a{6,7,2,3,4,5};
       cout<<FindPivot(a);
       return 0;
}