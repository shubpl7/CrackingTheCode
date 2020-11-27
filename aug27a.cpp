#include<bits/stdc++.h>
#define int long long
using namespace std;
int mask1=0,mask2=0,mask3=0;
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
		int n,m;
		cin>>n>>m;
		int mat[n][m];
              vector<int> mask1(n,0),mask2(n,0),mask3(n,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>mat[i][j];
                            if(mat[i][j]==1)
                            {
                                   if(j<=60)
                                   {
                                          mask1[i]|=(1LL<<j);
                                   }
                                   else if(j<=120)
                                   {
                                          mask2[i]|=(1LL<<(j-60));
                                   }
                                   else
                                   {
                                          mask3[i]|=(1LL<<(j-120));
                                   }
                                   
                            }
                            
			}
		}
		int count=0;
              for(int i=1;i<(1LL<<n);i++)
		{
			vector<int> v;
                     int m1=0,m2=0,m3=0;
			for(int j=0;j<n;j++)
			{
				if((i&(1LL<<j)))
				{
					//v.push_back(j);
                                   m1|=mask1[j];
                                   m2|=mask2[j];
                                   m3|=mask3[j];
                            }
			}
                     //cout<<"value of i is: "<<i<<endl;
			if((__builtin_popcount(m1)+ __builtin_popcount(m2) + __builtin_popcount(m3))==m)
			{
				//cout<<mask1<<endl;
				count++;
			}
			v.clear();
		}
		
		cout<<count<<endl;
	}
	return 0;
}
