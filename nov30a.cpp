#include<bits/stdc++.h>
#define int long long
using namespace std;


//Cracking the Code
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int t;
       cin>>t;
       while(t--)
       {
              int n,x;
              cin>>n>>x;
              vector<int> v(n);
              for(auto &y:v)
                     cin>>y;
              int i=0,count=0;
              for(int i=0;i<n-1;i++)
              {
                     if(v[i]>v[i+1])
                     {
                            if(v[i]>x && v[i+1]>=x){
                                   swap(x,v[i]);
                                   count++;
                                   //i--;
                            }
                     }
                     else
                            i++;
              }
              int flag=0;
              for(int i=0;i<n-1;i++)
              {
                     if(v[i]>v[i+1])
                     {
                            cout<<"-1\n";
                            flag=1;
                     }
              }
              if(!flag)
                     cout<<count<<endl;
       }
       return 0;
}