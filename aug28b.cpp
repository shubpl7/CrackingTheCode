#include<bits/stdc++.h>
using namespace std;
#define int long long


//Cracking the Code
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int w,h,n;
       cin>>w>>h>>n;
       set<int> H,W;
       multiset<int> hmax,wmax;
       H.insert(0);
       H.insert(h);
       W.insert(0);
       W.insert(w);
       hmax.insert(h);
       wmax.insert(w);
       for(int i=1;i<=n;i++)
       {
              char ch;
              int alpha;
              cin>>ch>>alpha;
              if(ch=='H')
              {
                     auto it=H.lower_bound(alpha);
                     auto it2=it;
                     it2--;
                     hmax.erase(hmax.lower_bound(*it-*it2));
                     hmax.insert(alpha-*it2);
                     hmax.insert(*it-alpha);
                     H.insert(alpha);
              }
              else if (ch=='V')
              {
                     auto it=W.lower_bound(alpha);
                     auto it2=it;
                     it2--;
                     wmax.erase(wmax.lower_bound(*it-*it2));
                     wmax.insert(alpha-*it2);
                     wmax.insert(*it-alpha);
                     W.insert(alpha);
              }
              cout<<(*hmax.rbegin())*(*wmax.rbegin())<<endl;
       }
       return 0;
}