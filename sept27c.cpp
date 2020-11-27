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

int palfirst(VI a,int l,int r,int key)
{
       if(l<=r)
       {
              // first occurence of the elememt.
              int mid=l+(r-l)/2;
              cout<<l<<" "<<r<<" "<<mid<<" "<<a[mid]<<endl;
              if(a[mid]==key && (mid==0 || a[mid-1]!=key))
                     return mid;
              else if(a[mid]>key)
                     return palfirst(a,l,mid-1,key);
              else
                    return  palfirst(a,mid+1,r,key);
       }
       return -1;
}
int pallast(VI a,int l,int r,int key)
{
       if(l<=r)
       {
              // last occurence of the elememt.
              int mid=l+(r-l)/2;
              cout<<l<<" "<<r<<" "<<mid<<" "<<a[mid]<<endl;
              if(a[mid]==key && (mid==a.size()-1 || a[mid+1]!=key))
                     return mid;
              else if(a[mid]>key)
                     return pallast(a,l,mid-1,key);
              else
                    return  pallast(a,mid+1,r,key);
       }
       return -1;
}
int findInSortedRoated(VI a,int key)
{
       int l=0,r=a.size()-1;
       while(l<=r)
       {
              int mid=l+(r-l)/2;
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
                     if(key>a[mid] && key<=a[a.size()-1])
                            l=mid+1;
                     else   
                            r=mid-1;
              }
              
       }
       return -1;
}

int FindPivot(VI &a)
{
	int s=0,e=a.size()-1;
	while(s<=e)
	{
		int mid=s+(e-s)/2;
		if(mid==a.size()-1 || a[mid+1]<a[mid])
			return a[mid];
		if(a[mid]>=a[s])
		{
			s=mid+1;
		}
		else
			e=mid-1;
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
       VI a{4,5,1,2,3};
       //cout<<pallast(a,0,a.size()-1,8)-palfirst(a,0,a.size()-1,8);
       cout<<findInSortedRoated(a,5);
       return 0;
}