#include<bits/stdc++.h>
using namespace std;


int main()
{
       
       int tc;
       // scanf("%d",&tc);
       cin>>tc;
       for(int t=1;t<=tc;t++)
       {
              int n;
              cin>>n;
              int arr[n];
              for(int i=0;i<n;i++)
              {
                     cin>>arr[i];
                     //scanf("%d",&arr[i]);
              }
              //algorithm
              int peak=0;
              for(int i=1;i<n-1;i++)
              {
                     if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                     {
                            peak++;
                     }
              }
              //printf("Case #%d: %d\n",t,peak);
              cout<<"Case #"<<t<<": "<<peak<<endl;

       }
       return 0;
}
