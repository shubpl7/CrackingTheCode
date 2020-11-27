#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


//Cracking the Code
int main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int arr[]={1,3,4,3,3,4,5,5};
       int n=sizeof(arr)/sizeof(arr[0]);
       int xor2=0;
       for(int i=0;i<n;i++)
       {
              xor2^=arr[i];
       }
       int mask = xor2 & ~(xor2-1);
       int first_odd_occurring_element=0;
       int second_odd_occurring_element=0;
       for(int i=0;i<n;i++)
       {
              if(mask&arr[i])
                     first_odd_occurring_element^=arr[i];
              else
                     second_odd_occurring_element^=arr[i];
       }
       cout<<first_odd_occurring_element<<" "<<second_odd_occurring_element;
       return 0;
}