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
       string s;
       cin>>s;
       // map<char,int> mp;
       // mp['A']=0;
       // mp['C']=0;
       // mp['G']=0;
       // mp['T']=0;
       int ans=0;
       int n=s.length();
       for(int i=0;i<n;)
       {
              char ch=s[i];
              int cnt=0;
              while(i<n && s[i]==ch)
              {
                     cnt++;
                     i++;
              }
              // if(cnt>mp[ch])
              // {
              //        mp[ch]=cnt;
              //        ans=max(ans,cnt);
              // }    
              ans=max(ans,cnt);   
       }
       cout<<ans;
       return 0;
}