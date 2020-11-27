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
       int arr[]={3,4,-7,8,-8,2,-2};
       int n=sizeof(arr)/sizeof(arr[0]);
       unordered_map<int,vector<int>> mp;
       int prefixSum[n];
       prefixSum[0]=arr[0];
       for(int i=1;i<n;i++)
       {
              prefixSum[i]=prefixSum[i-1]+arr[i];
       }
       int cnt=0;
       mp[0].push_back(-1);// here we initialized mp[0] with -1 because there can a null 
       //syb-array and it starts from the left of the first element so mp[0]=-1;
       for(int i=0;i<n;i++)
       {
              if(mp.find(prefixSum[i])!=mp.end())
              {
                     cnt+=mp[prefixSum[i]].size();
                     //Printing the sub-arrays with zero sum.
                     for(auto x: mp[prefixSum[i]])
                     {
                            for(int j=x+1;j<=i;j++)
                            {
                                   cout<<arr[j]<<" -> ";//printing the array
                            }
                            cout<<endl;
                     }
              }
              mp[prefixSum[i]].push_back(i);
       }
       cout<<"total no of subarrays are: "<<cnt;
       return 0;
}