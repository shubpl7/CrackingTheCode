#include <bits/stdc++.h>
using namespace std;
bool comp(string &a,string &b)
{
    if(a.length()>b.length())
    {
        if(a.substr(0,b.length())==b)
        {
            return true;
        }
            
    }
    else if(a.length()<b.length())
    {
        if(b.substr(0,a.length())==a)
        {
            return false;
        }
    }
    return a<b;
}
int main() {
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int n;
       cin>>n;
       vector<string> v(n);
       for(auto &it:v)
              cin>>it;
       sort(v.begin(),v.end(),comp);
       for(auto x:v)
              cout<<x<<endl;
       return 0;
}