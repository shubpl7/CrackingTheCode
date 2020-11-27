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
       int TestCases;
       cin>>TestCases;
       for(int tc=1;tc<=TestCases;tc++)
       {
              int n;
              cin>>n;
              vector<int> days(n);


              int x;
              int arr[10];
              int arr[x];
              int *p=new int[x]; //c++
              int *p = (int *)malloc(x*sizeof(int));//
              delete []p;

              p=NULL;
              vector<int> chitransh;
              chitransh.push_back(10);
              chitransh.push_back(5);
              chitransh.pop_back();



              for(int i=0;i<n;i++)
                     cin>>days[i];
              int MaxSoFar = -1;
              int RecordDays=0;
              for(int i=0;i<n;i++)
              {
                     if(days[i]>MaxSoFar)
                     {
                            if(i==(n-1) || days[i]>days[i+1])
                            {
                                   RecordDays++;
                            }
                            MaxSoFar = days[i];
                     }
              }
              cout<<"Case #"<<tc<<": "<<RecordDays<<endl;
       }
       return 0;
}