#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
int n;
VVI adj;
 int main()
 {    int sum=0;
     int n;
     cin>>n;
     adj.resize(n+1);
    
     int av[n+1];
     int pv[n+1];
     pv[0]=0;
     pv[1]=0;
     int sv[n+1];
     for(int i=2;i<=n;i++)
       {
              int p;
              cin>>p;
              pv[i]=p;
              adj[i].push_back(p);
              adj[p].push_back(i);
       }
     for(int i=1;i<n;i++)
     {
         cin>>sv[i];
         
     }
     av[0]=0;
     sv[0]=0;
     av[1]=sv[1];
     for(int i=2;i<n;i++)
     { int par=pv[i];
         if(sv[i]<0)
         { 
              int choice =35644;
              for(auto x:adj[i])
              {
                     if(x==par)
                        continue;
                     choice=min(choice,sv[x]);
              }
              if(choice==35644)
              {     
                     av[i]=0;
                     sv[i]=av[i]+sv[par];
              }
         
              else
              {
                     sv[i]=choice;
                     av[i]=sv[i]-sv[par];
                 
     }
         	
         } 
         else
         {
         	av[i]=sv[i]-sv[par];
         }
     }
    
     for(int i=0;i<=n;i++)
     {  
           sum=sum+av[i];
          	
         }
    cout<<sum;
     
 }