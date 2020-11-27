#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
namespace first{
       void fun()
       {
              cout<<"first";
       }
};
namespace second{
       void fun()
       {
              cout<<"second hi hi hi ";
       }
};
//Cracking the Code
using namespace second;
int main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       fun();

       return 0;
}